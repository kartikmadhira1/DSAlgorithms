
import numpy as np
class Node():
    def __init__(self, value):
        self.value=value
        #node has a list of edges 
        self.edges=[]
        self.visit=False
        self.next_node=None
    
class Stack():
    def __init__(self,head):
        self.queue_list=[head]
    def enqueue(self,value):
        self.queue_list.append(value)
    def peek(self):
        print (self.queue_list[0])
    def dequeue(self):
        del self.queue_list[0]

class Edge():
    def __init__(self,edge_value,from_node, to_node):
        self.value=edge_value
        self.from_node=from_node
        self.to_node=to_node
        
class Graph():
    #essentially graph is a collection of nodes and edges
    def __init__(self, nodes=[],edges=[]):
        self.nodes=nodes
        self.edges=edges
    def add_node(self, value):
        node=Node(value)
        self.nodes.append(node)
    def insert_edge(self,edge_value,from_node,to_node):
        #if from and to nodes are empty, create nodes and append
        from_node_tmp=None
        to_node_tmp=None
        for node in self.nodes:
            if(node.value==from_node):
                #print("coming inside")
                from_node_tmp=node
            if(node.value==to_node):
                to_node_tmp=node
        if(from_node_tmp is None):
            from_node_tmp=Node(from_node)
            self.nodes.append(from_node_tmp)
        if(to_node_tmp is None):
            to_node_tmp=Node(to_node)
            self.nodes.append(to_node_tmp)
        #better to have seperate lists for from and to nodes
        new_edge=Edge(edge_value,from_node_tmp,to_node_tmp)
        from_node_tmp.edges.append(new_edge)
        to_node_tmp.edges.append(new_edge)
        self.edges.append(new_edge)
    def get_edge_list(self):
        tmp_list=[]
        main_list=[]
        for i in range(0,len(self.edges)):
            print (i)
            tmp_list.append(self.edges[i].value)
            tmp_list.append(self.edges[i].from_node.value)
            tmp_list.append(self.edges[i].to_node.value)
            main_list.append(tmp_list)
            tmp_list=[]
        return main_list
    
    def get_adjacency_list(self):
        tmp_list=[]
        main_list=[]
        for i in range (0,len(self.nodes)):
            for j in range(0,len(self.nodes)):
                #print(node_values[i],self.edges[j].from_node.value)
                if (self.nodes[i].value==self.edges[j].from_node.value):
                    tmp_node=self.edges[j].from_node.value
                    a=[self.edges[j].to_node.value,self.edges[j].value]
                    tmp_list.append(a)
                    a=0
                elif (self.nodes[i].value==self.edges[j].to_node.value):
                    tmp_node=self.edges[j].to_node.value
                    a=[self.edges[j].from_node.value,self.edges[j].value]
                    tmp_list.append(a)
                    a=0
                #a=(tmp_node,self.edges[j].value)
            #print (self.edges[i].from_node.value)
            main_list.insert(self.nodes[i].value,tmp_list)
            tmp_list=[]
        return main_list
    
    def adjacency_matrix(self):
       # print (len(self.edges))
        a=np.zeros((len(self.edges)+1,len(self.edges)+1))
        for i in range(0,len(self.edges)):
            a[self.edges[i].from_node.value][self.edges[i].to_node.value]=self.edges[i].value
        return a
    
    #should return nthe highest node value found
    def max_node_val(self):
        max_node=0
        for nodes in self.nodes:
            if (nodes.value>=max_node):
                max_node=nodes.value
        return max_node
        
    def clear_visit_flags(self):
        #clear off visit values
        for nodes in self.nodes:
            self.visit=False
        
    def set_node_names(self,names):
        return list(names)
    
    def dfs(self,start_node_val):
        self.clear_visit_flags()
        self.ret_list=[]
        #self.node_start=node_start
        for node in self.nodes:
            if (node.value==start_node_val):
                node_start=node
        return self.dfs_helper(node_start)
        
    def dfs_helper(self,node_started):
        self.node_started=node_started
        ret_list=self.ret_list
        #print(node_started.value)
        if(node_started.visit is False):
            node_started.visit=True 
            ret_list.append(node_started.value)
            for i in range(0,len(node_started.edges)):
                if (node_started.edges[i].to_node.value==node_started.value):
                    self.dfs_helper(node_started.edges[i].from_node)
                else:
                    self.dfs_helper(node_started.edges[i].to_node)
        return ret_list
    def dfs_names(self,num):
        tmp_list=self.dfs(num)
        tmp_city_names=[]
        city_names=self.set_node_names()
        for i in range(0,len(tmp_list)):
            tmp_city_names.append(city_names[tmp_list[i]])
        return tmp_city_names


graph=Graph()
graph.insert_edge(51, 0, 1)     # MV <-> SF
graph.insert_edge(51, 1, 0)     # SF <-> MV
graph.insert_edge(9950, 0, 3)   # MV <-> Shanghai
graph.insert_edge(9950, 3, 0)   # Shanghai <-> MV
graph.insert_edge(10375, 0, 5)  # MV <-> Sao Paolo
graph.insert_edge(10375, 5, 0)  # Sao Paolo <-> MV
graph.insert_edge(9900, 1, 3)   # SF <-> Shanghai
graph.insert_edge(9900, 3, 1)   # Shanghai <-> SF
graph.insert_edge(9130, 1, 4)   # SF <-> Berlin
graph.insert_edge(9130, 4, 1)   # Berlin <-> SF
graph.insert_edge(9217, 2, 3)   # London <-> Shanghai
graph.insert_edge(9217, 3, 2)   # Shanghai <-> London
graph.insert_edge(932, 2, 4)    # London <-> Berlin
graph.insert_edge(932, 4, 2)    # Berlin <-> London
graph.insert_edge(9471, 2, 5)   # London <-> Sao Paolo
graph.insert_edge(9471, 5, 2)   # Sao Paolo <-> London1, 1, 3), (102, 1, 4), (103, 3, 4)]


