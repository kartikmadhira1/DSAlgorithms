
n=int(input())
graph=[[False for y in range(n)] for x in range(n)]
moves=list(map(int,input().split()))
start_X=moves[0]
start_Y=moves[1]
end_X=moves[2]
end_Y=moves[3]
bfs_queue=[]
move_queue=[]
end=0
#print(start_X,start_Y,end_X,end_Y)
bfs_queue.append([start_X,start_Y,0])
dam_dict={}
depth=0
while(len(bfs_queue)!=0):
    if (bfs_queue[0][0] in range(0,n) and bfs_queue[0][1] in range(0,n)):
        if(graph[bfs_queue[0][0]][bfs_queue[0][1]]==False):
            #print(bfs_queue[0][2])
            graph[bfs_queue[0][0]][bfs_queue[0][1]]=True
            move_queue.append('UL')
            #graph[bfs_queue[0][0]-2][bfs_queue[0][1]-1]=True
            if(dam_dict.get((bfs_queue[0][0]-2,bfs_queue[0][1]-1))==None):
                dam_dict[(bfs_queue[0][0]-2,bfs_queue[0][1]-1)]=[[bfs_queue[0][0],bfs_queue[0][1]],'UL',bfs_queue[0][2]+1]
            bfs_queue.append([bfs_queue[0][0]-2,bfs_queue[0][1]-1,bfs_queue[0][2]+1])
            move_queue.append('UR')
            #graph[bfs_queue[0][0]-2][bfs_queue[0][1]+1]=True
            if(dam_dict.get((bfs_queue[0][0]-2,bfs_queue[0][1]+1))==None):
                dam_dict[(bfs_queue[0][0]-2,bfs_queue[0][1]+1)]=[[bfs_queue[0][0],bfs_queue[0][1]],'UR',bfs_queue[0][2]+1]
            bfs_queue.append([bfs_queue[0][0]-2,bfs_queue[0][1]+1,bfs_queue[0][2]+1])
            
            if(dam_dict.get((bfs_queue[0][0],bfs_queue[0][1]+2))==None):
                dam_dict[(bfs_queue[0][0],bfs_queue[0][1]+2)]=[[bfs_queue[0][0],bfs_queue[0][1]],'R',bfs_queue[0][2]+1]
            bfs_queue.append([bfs_queue[0][0],bfs_queue[0][1]+2,bfs_queue[0][2]+1])
    
            if(dam_dict.get((bfs_queue[0][0]+2,bfs_queue[0][1]+1))==None):
                dam_dict[(bfs_queue[0][0]+2,bfs_queue[0][1]+1)]=[[bfs_queue[0][0],bfs_queue[0][1]],'LR',bfs_queue[0][2]+1]
            bfs_queue.append([bfs_queue[0][0]+2,bfs_queue[0][1]+1,bfs_queue[0][2]+1])
        
            if(dam_dict.get((bfs_queue[0][0]+2,bfs_queue[0][1]-1))==None):
                dam_dict[(bfs_queue[0][0]+2,bfs_queue[0][1]-1)]=[[bfs_queue[0][0],bfs_queue[0][1]],'LL',bfs_queue[0][2]+1]
            bfs_queue.append([bfs_queue[0][0]+2,bfs_queue[0][1]-1,bfs_queue[0][2]+1])
          
            if(dam_dict.get((bfs_queue[0][0],bfs_queue[0][1]-2))==None):
                dam_dict[(bfs_queue[0][0],bfs_queue[0][1]-2)]=[[bfs_queue[0][0],bfs_queue[0][1]],'L',bfs_queue[0][2]+1]
            bfs_queue.append([bfs_queue[0][0],bfs_queue[0][1]-2,bfs_queue[0][2]+1])
            del bfs_queue[0]
            #del move_queue[0]
           
        else:
            #del move_queue[0]
            del bfs_queue[0]
    else:
        #del move_queue[0]
        del bfs_queue[0]
        #print(bfs_queue)
    for a in bfs_queue:
        #print(a[0],a[1])
        if(a[0]==end_X and a[1]==end_Y):
            end=1
            break
    if(end==1):
        final_list=[]
        next_X=end_X
        next_Y=end_Y
        #print(next_X,next_Y,start_X,start_Y)
        while ((next_X,next_Y)!=(start_X,start_Y)):
            next_val_list=dam_dict[(next_X,next_Y)]
            final_list.append(next_val_list[1])
            next_X=next_val_list[0][0]
            next_Y=next_val_list[0][1]
        final_list.reverse()
        print(dam_dict[(end_X,end_Y)][2])
        print(*final_list)
        break
$print(bfs_queue)
if(len(bfs_queue)==0):
    print('Impossible')


