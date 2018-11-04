#include <iostream>
#include <limits>

using namespace std;

void selectionSort(int arr[],int arrSize);

void selectionSort(int arr[], int arrSize) {
    for(int i=0;i<arrSize;i++){
        int least=std::numeric_limits<int>::max();
        int index=0;
        for(int j=i;j<arrSize;j++) {
            if (arr[j] < least) {
                least = arr[j];
                index = j;
            }
        }
        swap(arr[i],arr[index]);
    }
}

int main(){
    int arr[]={82,23,726,35,943,762,420};
    int arrSize= sizeof(arr)/sizeof(int);
    cout<<"unsorted array is"<<'\n';
    for (int i=0;i<arrSize;i++){

        cout<<arr[i]<<' ';
    }
    selectionSort(arr,arrSize);
    cout<<'\n'<<"sorted array is"<<'\n';
    for (int i=0;i<arrSize;i++){
        cout<<arr[i]<<' ';
    }

}