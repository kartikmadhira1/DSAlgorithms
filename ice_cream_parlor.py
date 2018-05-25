def icecreamParlor(m, arr):
    ret_arr=[]
    #alloting a freq array for the costs associated
    freq_array=[0]*10000
    for i in range (0, len(arr)):
        freq_array[arr[i]]+=1
    #for every value associated check if the sum exists
    for i in range(0,len(arr)):
        pair_num=m-arr[i]
        freq_array[arr[i]]-=1
        if(freq_array[pair_num]>0):
            ret_arr.append(i+1)
            ret_arr.append(arr.index(pair_num,i+1,len(arr)-1)+1)
            break
    return ret_arr

if __name__ == "__main__":
    t = int(input().strip())
    for a0 in range(t):
        m = int(input().strip())
        n = int(input().strip())
        arr = list(map(int, input().strip().split(' ')))
        result = icecreamParlor(m, arr)
        print (" ".join(map(str, result)))

