#include <iostream>

using namespace std;
/*
 * it will have the following methods:
 * 1. Get(i) - returns value of selected index.
 * 2. Insert(i,v) - puts a value v at index i
 * 3. Search(v) - returns the first occurance of v
 * 4. Remove(i) - removes item in ith index.
 */

class List{
private:
    //one variable holds the list and the other keeps track of the array
    int *arr;
    int arrLen;
public:
    List();
    ~List();
    int get(int i);
    int insert(int i, int v);
    void printList();
    int search(int v);
    int remove(int i);
};

List::List() {
arrLen=0;
}

List::~List() {
}

int List::remove(int i) {
    //removes the ith element from the array. same sequence as the insertion one.
    int *oldArray=arr;
    //create a new array
    int k=0;
    arrLen-=1;
    arr= new int[arrLen];
    for (int j=0;j<arrLen;j++){
        if(j!=i){
            arr[j]=oldArray[k];
            k++;
        }
        else{
            arr[j]=oldArray[k+1];
            k+=2;
        }
    }
delete [] oldArray;
}


int List::get(int i)  {
    //iterate through the loop but get the one at the index.
    int j=0;
    if(i<arrLen){
        while(j!=i){
            *(arr+1);
        }
        return *arr;
    }
    else{
        return -1;
    }
}

int List::insert(int i, int v) {
    //make a copy of the current array
    if(i<0 || i>arrLen){
        return -1;
    }
    int *oldArray=arr;
    //increase the size of array by one to accomodate the value
        arrLen += 1;
        int k=0;
        //create a new array and change the value at the poisiton provided
        arr = new int[arrLen];
        for (int j = 0; j <arrLen; j++) {
            if (j == i) {
                arr[j] = v;
            } else {
                arr[j] = oldArray[k];\
                k++;
            }
        }
    delete [] oldArray;
}

void List::printList() {
    if(arrLen>=0){
    for(int i=0;i<arrLen;i++) {
        cout << arr[i] << '\n';
    }
    }
    else{
        cout<<"empty array"<<'\n';

    }
}

int List::search(int v){
    for(int i=0;i<arrLen;i++){
        if(arr[i]==v){
            cout<<"found at "<<i<<" !"<<"\n";
            return 1;
        }
    }
    cout<<"No values found!"<<'\n';
    return 0;
}

int main (){
   List list=List();
   list.insert(0,1);
   list.insert(1,2);
   list.insert(2,3);
   list.insert(3,4);
   list.insert(1,3);
   cout<<"Before Removal"<<'\n';
   list.printList();
   list.remove(2);
   list.remove(1);
   cout<<"After Removal"<<'\n';
   list.printList();


    return 1;
}