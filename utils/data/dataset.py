import numpy as np
import os
from os import listdir
from os.path import isfile, join

def load_graphs_from_file(file_name):
    data_list = []
    edge_list = []
    target_list = []
    
    with open(file_name,'r') as f:
        for line in f:
            if len(line.strip()) == 0:
                data_list.append([edge_list,target_list])
                edge_list = []
                target_list = []
            else:
                digits = []
                line_tokens = line.split(" ")

                if line_tokens[0] == "?":
                    for i in range(1, len(line_tokens)):
                        
                        digits.append(int(line_tokens[i]))
                    target_list.append(digits)
                else:
                    for i in range(len(line_tokens)):
                        digits.append(int(line_tokens[i]))
                    edge_list.append(digits)
    # print(data_list)
    return data_list

def load_program_graphs_from_directory(directory,is_train=True,n_classes=3, data_percentage=1):
    data_list = []
    if is_train == True:
            dir_path =  os.path.join(directory,"train")
    else:
            dir_path =  os.path.join(directory,"test")
    i = 0
    lookup = {}
    for f in listdir(dir_path):
      if isfile(join(dir_path, f)):
        i = i + 1
        lookup[i] = join(dir_path, f)

    for i in range(1,(n_classes+1)):
        path = lookup[i]
        print(path)
        label = i
        data_list_class_i = []
        edge_list_class_i = []
        target_list_class_i = []

        with open(path,'r') as f:
            for line in f: 
                if len(line.strip()) == 0:

                    data_list_class_i.append([edge_list_class_i,target_list_class_i])
                    edge_list_class_i = []
                    target_list_class_i = []
                else:
                    digits = []
                    line_tokens = line.split(" ")
                    
                    if line_tokens[0] == "?":

                        target_list_class_i.append([label])
                    else:
                        for j in range(len(line_tokens)):
                            digits.append(int(line_tokens[j]))
                        edge_list_class_i.append(digits)

        if data_percentage != 1:
            slicing = int(len(data_list_class_i)*data_percentage)
            data_list_class_i = data_list_class_i[:slicing]

        data_list.extend(data_list_class_i)

    return data_list

def find_max_edge_id(data_list):
    max_edge_id = 0
    for data in data_list:
        edges = data[0]
        for item in edges:
            if item[1] > max_edge_id:
                max_edge_id = item[1]
    return max_edge_id

def find_max_node_id(data_list):
    max_node_id = 0
    for data in data_list:
        edges = data[0]
        for item in edges:
            if item[0] > max_node_id:
                max_node_id = item[0]
            if item[2] > max_node_id:
                max_node_id = item[2]
    return max_node_id
    # return 48

def find_max_task_id(data_list):
    max_node_id = 0
    for data in data_list:
        targe = data[1]
        for item in targe:
            if item[0] > max_node_id:
                max_node_id = item[0]
    return max_node_id

def split_set(data_list,num):
    n_examples = len(data_list)
    idx = range(n_examples)
    train = idx[:num]
    val = idx[-num:]
    return np.array(data_list)[train],np.array(data_list)[val]

def split_set_by_percentage(data_list,percentage):
    n_examples = len(data_list)
    train_num = int(n_examples * percentage)

    idx = range(n_examples)
    train = idx[:train_num]
    val = idx[train_num:n_examples]
    return np.array(data_list)[train],np.array(data_list)[val]

def data_convert(data_list, n_annotation_dim):
    n_nodes = find_max_node_id(data_list)
    n_tasks = find_max_task_id(data_list)
    task_data_list = []
    for i in range(n_tasks):
        task_data_list.append([])

    for item in data_list:
        edge_list = item[0]
        target_list = item[1]
        for target in target_list:
            task_type = target[0]
            task_output = target[-1]
            annotation = np.zeros([n_nodes, n_annotation_dim])
            annotation[target[1]-1][0] = 0
            task_data_list[task_type-1].append([edge_list, annotation, task_output])
    return task_data_list

def data_convert_for_program_data(data_list, n_annotation_dim):
    # n_nodes = find_max_node_id(data_list)
    n_nodes = 111
    task_data_list = []
 
    for item in data_list:
        edge_list = item[0]
        target_list = item[1]
        for target in target_list:
            task_type = target[0]
            task_output = target[-1]
            annotation = np.zeros([n_nodes, n_annotation_dim])   
            for edge in edge_list:
                src_idx = edge[0]
                # print(src_idx)
                annotation[src_idx-1][0] = 1
          
            task_data_list.append([edge_list, annotation, task_output])
    return task_data_list

def create_adjacency_matrix(edges, n_nodes, n_edge_types):
    a = np.zeros([n_nodes, n_nodes * n_edge_types * 2])
    
    for edge in edges:
        src_idx = edge[0]
        e_type = edge[1]
        tgt_idx = edge[2]
       
        a[tgt_idx-1][(e_type - 1) * n_nodes + src_idx - 1] =  1
        a[src_idx-1][(e_type - 1 + n_edge_types) * n_nodes + tgt_idx - 1] =  1
    return a


class bAbIDataset():
    """
    Load bAbI tasks for GGNN

    Example data:
        1 1 2
        2 1 3
        ? 1 2 1
    Explaination of last line : ? 1 2 1 
    ==> question_types = 2
    ==> task_type = 1
    ==> task_output = 1
    """

    def __init__(self, path, question_types, is_train):
       
        all_data = load_graphs_from_file(path)
      
        self.n_edge_types =  find_max_edge_id(all_data)
        self.n_tasks = find_max_task_id(all_data)
        self.n_node = find_max_node_id(all_data)
        all_task_train_data, all_task_val_data = split_set(all_data,50)
       
        if is_train:
            all_task_train_data = data_convert(all_task_train_data, 1)

            self.data = all_task_train_data[question_types]

        else:
            all_task_val_data = data_convert(all_task_val_data, 1)
            self.data = all_task_val_data[question_types]

    def __getitem__(self, index):
        # print(self.data[index])
        
        am = create_adjacency_matrix(self.data[index][0], self.n_node, self.n_edge_types)
        annotation = self.data[index][1]
        target = self.data[index][2] - 1
        return am, annotation, target

    def __len__(self):
        return len(self.data)

class bAbIDataset2():
   
    def __init__(self, path, is_train, n_classes=3,data_percentage=1):
       
        all_data = load_program_graphs_from_directory(path,is_train,n_classes,data_percentage)
        all_data = np.array(all_data)[0:len(all_data)]
       
        if is_train == True:
            print("Number of all training data : " + str(len(all_data)))
        else:
            print("Number of all testing data : " + str(len(all_data)))
        self.n_edge_types =  find_max_edge_id(all_data)
        # print("Edge types : " + str(self.n_edge_types))
        self.n_tasks = find_max_task_id(all_data)
        # self.n_node = find_max_node_id(all_data)
        self.n_node = 111
        
        all_data = data_convert_for_program_data(all_data,1)

        
        self.data = all_data
     
    def __getitem__(self, index):
        # print(index)
        # print(self.data)
        # print(self.data[index])
        # print(self.data[index][0])
        # print(self.data[index][1])
        # print(self.data[index])
        am = create_adjacency_matrix(self.data[index][0], self.n_node, self.n_edge_types)
        annotation = self.data[index][1]
        target = self.data[index][2] - 1
        # print("Target : " + str(target))
        return am, annotation, target

    def __len__(self):
        return len(self.data)

