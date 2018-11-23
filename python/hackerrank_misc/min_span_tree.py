import numpy as np
class Node():
    def __init__(self, value):
        self.value=value
        #node has a list of edges 
        self.edges=[]
        self.visit=False
        self.distance=None
        self.heap_id=None
        
    
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
        #better tohave seperate lists for from and to nodes
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
        
    #def set_node_names(self,names):
     #   self.city_list=
    
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
        for i in range(0,len(tmp_list)):
            tmp_city_names.append(self.set_node_names.city_list[tmp_list[i]])
        return tmp_city_names
    def bfs(self,start_node_val):
        #clearing all the visit flags
        self.clear_visit_flags()
        self.ret_list=[]
        for i in range(0,len(self.nodes)):
            if(self.nodes[i].value==start_node_val):
                node_start=self.nodes[i]
        return self.bfs_helper(node_start)
    
    def bfs_helper(self, start_node):
        self.ret_list_bfs=[]
        self.start_node=start_node
        tmp_stack_obj=Stack(None) 
        while (len(tmp_stack_obj.queue_list)!=0):
            #print (tmp_stack_obj.queue_list[:])
            #print(start_node.value)
            if (start_node.visit==False):
                start_node.visit=True
                self.ret_list_bfs.append(start_node.value)
                for i in range(0,len(start_node.edges)):
                    #print(start_node.edges[i].to_node.value)
                    if(start_node.edges[i].to_node.value!=start_node.value):
                        tmp_stack_obj.enqueue(start_node.edges[i].to_node)
                        #print(start_node.edges[i].to_node.value)        
                tmp_stack_obj.dequeue()
                if (len(tmp_stack_obj.queue_list)==0):
                    break
                print("----------")
                for i in range(0, len(tmp_stack_obj.queue_list)):
                    print(tmp_stack_obj.queue_list[i].value)
                print("----------")
                start_node=tmp_stack_obj.queue_list[0]
            else:
                break
                
        return self.ret_list_bfs
    
    
import math
class Heap():
    def __init__(self,heap_array):
        self.heap_array=heap_array
    #putting helper functions to get parent left and right nodes
    def parent(self,i):
        return math.floor((i-1)/2)
    def array(self):
        return self.heap_array
    def left(self,i):
        return 2*i+1
    def right(self,i):
        return 2*i+2
    def extracted_queue(self):
        return self.extracted_array
    def heapify(self,i):
        #print (self.heap_array[i],self.left(i),self.right(i))
        tmp_cont=-1
        if (self.left(i)<len(self.heap_array)):
            if(self.heap_array[i].distance>self.heap_array[self.left(i)].distance):
                tmp_cont=self.left(i)
            else:
                tmp_cont=i
        if (self.right(i)<len(self.heap_array)):
            if(self.heap_array[tmp_cont].distance>self.heap_array[self.right(i)].distance):
                tmp_cont=self.right(i)
       # print(tmp_cont,i)
        #exchanging tmp_cont and heap_array[i]
        if(tmp_cont!=i and tmp_cont!=-1):
            #print("lol")
            tmp_var=self.heap_array[i]
            self.heap_array[i]=self.heap_array[tmp_cont]
            self.heap_array[tmp_cont]=tmp_var
            self.heapify(tmp_cont)
        #return self.heap_array 
        
    def build_min_heap(self):
        self.extracted_array=[]
        for i in range(1,(len(self.heap_array))):
            self.heapify(i)
            #print(self.heap_array)
        self.heapify(0)
        return self.heap_array

    def extract_min(self):
        if(len(self.heap_array)>1):
            self.extracted_array.append(self.heap_array[0])
            self.heap_array[0]=self.heap_array[len(self.heap_array)-1]
            del self.heap_array[len(self.heap_array)-1]
            self.heapify(0)
        #return self.heap_array
    
    def decrease_key(self,i,key):
        self.heap_array[i].distance=key
        #print(i,self.heap_array[i].value,self.heap_array[i].distance)
        #print('---')
        
        while (i>0 and (self.heap_array[i].distance<=self.heap_array[self.parent(i)].distance)):
            #print(i,self.heap_array[i].distance,self.heap_array[self.parent(i)].distance)
            #self.heap_array[i].distance=self.heap_array[self.parent(i)].distance) 
            tmp_var=self.heap_array[i]
            self.heap_array[i]=self.heap_array[self.parent(i)]
            self.heap_array[self.parent(i)]=tmp_var
            #print(self.heap_array[i].value,self.heap_array[self.parent(i)].value)
            i=self.parent(i)
        return self.heap_array

graph=Graph()
graph.insert_edge(3,0,1)
graph.insert_edge(6,0,3)
graph.insert_edge(4,1,3)
graph.insert_edge(4,0,2)

graph.insert_edge(7,2,4)
graph.insert_edge(4,3,4)
graph.insert_edge(4,4,6)
graph.insert_edge(5,3,5)
graph.insert_edge(5,5,6)
graph.nodes[0].edges[2].to_node.value
#gra#print(len(graph.nodes[0].edges))


# In[161]:


def min_span(graph,start):
    tmp_priq=[0]*len(graph.nodes)
    for i in range(0,len(graph.nodes)):
        if(start==i):
            graph.nodes[i].distance=0
            #graph.nodes[i].heap_id=1
        else:
            graph.nodes[i].distance=math.inf
            #graph.nodes[i].heap_id=0
    tmp_priq=graph.nodes
    set_S=[]
    priq=Heap(tmp_priq)
    j=0
    final_array=[]
    priq.build_min_heap()
    
    node_list=list('UDACITY')
    string_dict={}
    k=0
    for a in node_list:
        string_dict[k]=a
        k+=1
    set_S.append(priq.heap_array[0])
    final_dict={}
    #print(priq.heap_array[0].distance)
    while(len(priq.heap_array)!=1):
        #print(set_S[j].value)
        MST_array=[]
        priq.extract_min()
        #print(set_S[j].value)
        for i in range (0,len(set_S[j].edges)):
            #print(i,set_S[j].distance,set_S[j].edges[i].value,set_S[j].edges[i].to_node.distance)
            if(set_S[j].distance+set_S[j].edges[i].value<set_S[j].edges[i].to_node.distance):
                set_S[j].edges[i].to_node.distance=set_S[j].distance+set_S[j].edges[i].value
                #print(set_S[j].edges[i].to_node.value,set_S[j].distance+set_S[j].edges[i].value,set_S[j].distance+set_S[j].edges[i].value)
                #priq.decrease_key(,set_S[j].distance+set_S[j].edges[i].value)
                #priq.heapify(0)
                node_to=(string_dict[set_S[j].edges[i].to_node.value],set_S[j].edges[i].value)
                node_from=(string_dict[set_S[j].edges[i].from_node.value],set_S[j].edges[i].value)
                MST_array.append(node_to)
                MST_array.append(node_from)
                priq.build_min_heap()
                #final_array.append(a)
        final_dict[string_dict[set_S[j].value]]=MST_array
        set_S.append(priq.heap_array[0])
        j+=1
    
    for i in range(0,len(set_S)):
        print(set_S[i].value)
    return final_dict


# In[162]:


min_span(graph,0)

