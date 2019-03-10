package algs24;
import stdlib.*;


public class Heap {

	public static <T extends Comparable<? super T>> void sort(T[] pq) {
		int N = pq.length;
		for (int k = N/2; k >= 1; k--) {
			sink(pq, k, N);
		}
		while (N > 1) {
			exch(pq, 1, N);
			N--;
			sink(pq, 1, N);
		}
	}

	

	private static <T extends Comparable<? super T>> void sink(T[] pq, int k, int N) {
		while (2*k <= N) {
			int j = 2*k;
			if (j < N && less(pq, j, j+1)) j++;
			if (!less(pq, k, j)) break;
			exch(pq, k, j);
			k = j;
		}
	}

	
	private static <T extends Comparable<? super T>> boolean less(T[] pq, int i, int j) {
		if (COUNT_OPS) DoublingTest.incOps ();
		return pq[i-1].compareTo(pq[j-1]) < 0;
	}

	private static <T> void exch(T[] pq, int i, int j) {
		if (COUNT_OPS) DoublingTest.incOps ();
		T swap = pq[i-1];
		pq[i-1] = pq[j-1];
		pq[j-1] = swap;
	}

	
	private static <T extends Comparable<? super T>> boolean less(T v, T w) {
		if (COUNT_OPS) DoublingTest.incOps ();
		return (v.compareTo(w) < 0);
	}


	
	private static <T extends Comparable<? super T>> boolean isSorted(T[] a) {
		for (int i = 1; i < a.length; i++)
			if (less(a[i], a[i-1])) return false;
		return true;
	}


	
	private static <T> void show(T[] a) {
		for (T element : a) {
			StdOut.println(element);
		}
	}


	
	private static boolean COUNT_OPS = false;

}
