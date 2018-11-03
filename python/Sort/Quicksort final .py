
# coding: utf-8

# In[9]:


def Quicksort(array):
    n=len(array)
    counter=0
    arrIndex=0
    if (n>1):
        #pivot is the last element.
        #counter variable to increase the index when swap happens
        pivot=array[n-1-counter]
        for i in range (0,n-1):
            if(array[arrIndex]>=array[n-1-counter]):
                #exchanging the value next to the pivot
                tmpVar1=array[n-1-counter]
                tmpVar2=array[n-2-counter]
                array[n-1-counter]=array[arrIndex]
                array[arrIndex]=tmpVar2
                array[n-2-counter]=tmpVar1
                counter+=1
            else:
                #index to increase when pivot is greater than first element
                arrIndex+=1
        upperArray=array[n-counter:n]
        upperTmpArray=Quicksort(upperArray)
        array[n-counter:n]=upperTmpArray
        lowerArray=array[0:n-1-counter]
        lowerTmpArray=Quicksort(lowerArray)
        array[0:n-1-counter]=lowerTmpArray
    return array


# In[30]:


import random 
test=random.sample(range(1,10000),999)
test


# In[32]:


import time
start = time.time()
Quicksort(test)
end = time.time()
print(end - start)

