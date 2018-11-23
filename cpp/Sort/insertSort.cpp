#include <iostream>
#include <limits>

using namespace std;

/*
 * Algorithm:
 * 1. For every element i in arr:
 * 2.   Take i+1th element and swap if its smaller.
 * This is makes the number of swaps lesser than other sorts.
 */

void insertionSort(int arr[],int arrSize);

void insertionSort(int arr[], int arrSize) {
    int j=1;
    for(int i=0;i<arrSize-1;i++){
        j=i+1;
        while(arr[j]<arr[j-1] && j>0){
            swap(arr[j],arr[j-1]);
            j--;
        }
    }
}

int main(){
    int arr[]={82,23,726,35,943,762,420,9923,1,8,9348,830};
    int arrSize= sizeof(arr)/sizeof(int);
    cout<<"unsorted array is"<<'\n';
    for (int i=0;i<arrSize;i++){
        cout<<arr[i]<<' ';
    }
    insertionSort(arr,arrSize);
    cout<<'\n'<<"sorted array is"<<'\n';
    for (int i=0;i<arrSize;i++){
        cout<<arr[i]<<' ';
    }

}