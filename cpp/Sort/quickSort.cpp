#include <iostream>

using namespace std;

/*
 * Algorithm:
 * 1. Input an array and use the last element as the pivot
 * 2. Compare each element after pivot and do inplace replacement until pivot comes to middle
 * 3. Recursively do 1-2 after splitting the array.
 */

int *quickSort(int *arr, int startPos,int endPos);

int main(){
    int arr[]={4,3,224,2,655,22,233,22,22,34,223,23,4334,5334,222,1,2434,66,0};

    int len=sizeof(arr)/sizeof(arr[1]);
    for(int i=0;i<len;i++){
        cout<<arr[i]<<'\n';
    }
    cout<<'\n';
    int *sorted=quickSort(arr,0,len);
    for(int i=0;i<len;i++){
        cout<<*(sorted+i)<<'\n';
    }
}

int *quickSort(int *arr, int startPos,int endPos) {
    //take the last element of the array
    bool anyChange = false;
    int pivot=endPos-1;
    if((endPos-startPos)>=1) {
        for (int i = startPos; i < (endPos-1); i++) {
            if ((pivot-i)>=1) {
                if ((arr[i] > arr[pivot])) {
                    anyChange = true;
                    //do an inplace exchange of elements;
                    int firstTemp = arr[i];
                    int thirdTemp = arr[pivot];
                    arr[i] = arr[pivot - 1];
                    arr[pivot] = firstTemp;
                    arr[pivot - 1] = thirdTemp;
                    pivot = pivot - 1;
                    i = i - 1;
                }
            } else {
                int firstTemp = arr[i];
                arr[i] = arr[pivot];
                int thirdTemp = arr[pivot];
                arr[pivot] = firstTemp;
                pivot-=1;
                break;
            }
        }

        if(!anyChange){
            quickSort(arr,0,endPos-1);
        }
        quickSort(arr, 0, pivot - 1);
        quickSort(arr , pivot+1, endPos);
        return arr;
    }
}
