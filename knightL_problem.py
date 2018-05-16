
# coding: utf-8

# In[6]:


class Node():
    def __init__(self, value):
        self.value=value
        self.visited=False
        self.depth=0
def coord(node,a,b):
    pre_stack=[]
    ret_list=[]
    x2_1=node.value[0]+a
    y2_1=node.value[1]+b
    pre_stack.append(Node([x2_1,y2_1]))
    x2_2=node.value[0]-a
    y2_2=node.value[1]-b
    pre_stack.append(Node([x2_2,y2_2]))
    x2_3=node.value[0]+b
    y2_3=node.value[1]+a
    pre_stack.append(Node([x2_3,y2_3]))
    x2_4=node.value[0]-b
    y2_4=node.value[1]-a
    pre_stack.append(Node([x2_4,y2_4]))
    x2_5=node.value[0]+a
    y2_5=node.value[1]-b
    pre_stack.append(Node([x2_5,y2_5]))
    x2_6=node.value[0]-a
    y2_6=node.value[1]+b
    pre_stack.append(Node([x2_6,y2_6]))
    x2_7=node.value[0]+b
    y2_7=node.value[1]-a
    pre_stack.append(Node([x2_7,y2_7]))
    x2_8=node.value[0]-b
    y2_8=node.value[1]+a
    pre_stack.append(Node([x2_8,y2_8]))
    return pre_stack
def bfs(graph1,a1,b1,n):
    queue=[]
    graph[0][0].visited=True
    queue.append(graph[0][0])
    i=0
    del_var=0
    while(len(queue)!=0):
        #print(queue[0].value)
        x=queue[0].value[0]
        y=queue[0].value[1]
        graph[x][y].visited=True
        list_ret=coord(Node([x,y]),a1,b1)
        for nodes in list_ret:
            x_graph=nodes.value[0]
            y_graph=nodes.value[1]
            if (0<=x_graph<=(n-1) and 0<=y_graph<=(n-1)):
                if(graph[x_graph][y_graph].visited==False):
                    queue.append(graph[x_graph][y_graph])
                    graph[x_graph][y_graph].visited=True
                    graph[x_graph][y_graph].depth=queue[0].depth+1
                    if(graph[x_graph][y_graph].value==[n-1,n-1]):
                        return (queue[0].depth+1)
        del queue[0]
        i+=1
    return -1


# In[17]:


import copy
n=int(input())
graph = [[] for k in range(n)]
for l in range(0,n):
    for m in range(0,n):
        graph[l].append(Node([l,m]))
import time
start = time.time()
for i in range(1,n):
    values=[]
    for j in range(1,n):
        graph1 = [[] for k in range(n)]
        graph1=copy.deepcopy(graph)
        graph1 = [sublist[:] for sublist in graph]
        for l in range(0,n):
            for m in range(0,n):
                print(graph1[l][m].value,graph1[l][m].depth)
        print(id(graph1[i][j]),id(graph[i][j]))
        #graph = [[False]*n for k in range(n)]
        ret_val=bfs(graph1,i,j,n)
        #print(ret_val)
        values.append(ret_val)
    #print(values)
    print(*values)
end = time.time()
print(end - start)


# ##### a=[1,2,3,4]
# a1=a[1:]
# a1

# In[28]:


graph = [[] for k in range(n)]
for l in range(0,n):
    for m in range(0,n):
        graph[l].append(Node([l,m]))


# In[29]:


for i in range(0,5):
    graph1=graph[:]
    for l in range(0,n):
        for m in range(0,n):
            print(graph[l][m].value,grapg)

