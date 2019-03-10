

package net.minecraftforge.fml.common.toposort;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.NoSuchElementException;
import java.util.Set;
import java.util.SortedSet;
import java.util.TreeSet;

import net.minecraftforge.fml.common.FMLLog;

import com.google.common.collect.Sets;
import com.google.common.collect.Sets.SetView;


public class TopologicalSort
{
    public static class DirectedGraph<T> implements Iterable<T>
    {
        private final Map<T, SortedSet<T>> graph = new HashMap<T, SortedSet<T>>();
        private List<T> orderedNodes = new ArrayList<T>();

        public boolean addNode(T node)
        {
            
            if (graph.containsKey(node))
            {
                return false;
            }

            orderedNodes.add(node);
            graph.put(node, new TreeSet<T>(Comparator.comparingInt(o -> orderedNodes.indexOf(o))));
            return true;
        }

        public void addEdge(T from, T to)
        {
            if (!(graph.containsKey(from) && graph.containsKey(to)))
            {
                throw new NoSuchElementException("Missing nodes from graph");
            }

            graph.get(from).add(to);
        }

        public void removeEdge(T from, T to)
        {
            if (!(graph.containsKey(from) && graph.containsKey(to)))
            {
                throw new NoSuchElementException("Missing nodes from graph");
            }

            graph.get(from).remove(to);
        }

        public boolean edgeExists(T from, T to)
        {
            if (!(graph.containsKey(from) && graph.containsKey(to)))
            {
                throw new NoSuchElementException("Missing nodes from graph");
            }

            return graph.get(from).contains(to);
        }

        public Set<T> edgesFrom(T from)
        {
            if (!graph.containsKey(from))
            {
                throw new NoSuchElementException("Missing node from graph");
            }

            return Collections.unmodifiableSortedSet(graph.get(from));
        }
        @Override
        public Iterator<T> iterator()
        {
            return orderedNodes.iterator();
        }

        public int size()
        {
            return graph.size();
        }

        public boolean isEmpty()
        {
            return graph.isEmpty();
        }

        @Override
        public String toString()
        {
            return graph.toString();
        }
    }

    
    public static <T> List<T> topologicalSort(DirectedGraph<T> graph)
    {
        DirectedGraph<T> rGraph = reverse(graph);
        List<T> sortedResult = new ArrayList<T>();
        Set<T> visitedNodes = new HashSet<T>();
        
        Set<T> expandedNodes = new HashSet<T>();

        for (T node : rGraph)
        {
            explore(node, rGraph, sortedResult, visitedNodes, expandedNodes);
        }

        return sortedResult;
    }

    public static <T> DirectedGraph<T> reverse(DirectedGraph<T> graph)
    {
        DirectedGraph<T> result = new DirectedGraph<T>();

        for (T node : graph)
        {
            result.addNode(node);
        }

        for (T from : graph)
        {
            for (T to : graph.edgesFrom(from))
            {
                result.addEdge(to, from);
            }
        }

        return result;
    }

    public static <T> void explore(T node, DirectedGraph<T> graph, List<T> sortedResult, Set<T> visitedNodes, Set<T> expandedNodes)
    {
        
        if (visitedNodes.contains(node))
        {
            
            if (expandedNodes.contains(node))
            {
                
                return;
            }

            FMLLog.log.fatal("Mod Sorting failed.");
            FMLLog.log.fatal("Visiting node {}", node);
            FMLLog.log.fatal("Current sorted list : {}", sortedResult);
            FMLLog.log.fatal("Visited set for this node : {}", visitedNodes);
            FMLLog.log.fatal("Explored node set : {}", expandedNodes);
            SetView<T> cycleList = Sets.difference(visitedNodes, expandedNodes);
            FMLLog.log.fatal("Likely cycle is in : {}", cycleList);
            throw new ModSortingException("There was a cycle detected in the input graph, sorting is not possible", node, cycleList);
        }

        
        visitedNodes.add(node);

        
        for (T inbound : graph.edgesFrom(node))
        {
            explore(inbound, graph, sortedResult, visitedNodes, expandedNodes);
        }

        
        sortedResult.add(node);
        
        expandedNodes.add(node);
    }
}