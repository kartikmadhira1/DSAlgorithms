
# coding: utf-8

# In[18]:


from min_tree_trav.graph import Graph
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
min_span(graph,0)

