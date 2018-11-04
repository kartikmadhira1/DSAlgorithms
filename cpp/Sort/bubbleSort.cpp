#include <iostream>

using namespace std;

void bubbleSort(int arr[],int arrSize){
    bool isSwapped;
    //using a do while statement to keep the complexity to O(n) for cases that are possible.
    int unsortSize=arrSize;
    do{
        //this boolean will be used to know if we need to terminate the O(N2) complexity
        isSwapped= false;
        for(int i=0;i<unsortSize-1;++i){
            if(arr[i]>arr[i+1]){
                swap(arr[i],arr[i+1]);
                isSwapped=true;
            }
        }
        --unsortSize;
    }
    //if the elements are swapped, we dont need to traverse all over again
    while(isSwapped);
}


void bubbleSort(int arr[],int arrSize);
int main(){
    int arr[]={23,82,726,35,943,762,420};
    int arrSize= sizeof(arr)/sizeof(int);
    cout<<"unsorted array is"<<'\n';
    for (int i=0;i<arrSize;i++){

        cout<<arr[i]<<' ';
    }
    bubbleSort(arr,arrSize);
    cout<<'\n'<<"sorted array is"<<'\n';
    for (int i=0;i<arrSize;i++){
        cout<<arr[i]<<' ';
    }

}