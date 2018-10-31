#include <iostream>
// Methods of the singly linked list
/*
 * Insert
 * Get position
 * Insert at a particular position
 * Delete from a position
 */

using namespace std;
//create a Node class first which has a value and a pointer pointing to the next Node
template <typename T>
class Node{
public: //should all this be public????/
    T value;
    Node<T> *next=NULL;
};

//define a class of Linkedlist that runs on the simple nodes
template <typename T>
class LinkedList{
public:
    //will this be a pointer?
    Node<T> *head=NULL;
    Node<T> *tail;
    void insert(Node<T> *node);
    void printList();
    int getPos(T value);
    Node<T> *getValPos(int pos);
    void insertPos(Node<T> *value, int pos);
    void deletePos( int pos);
};

template <typename T>
void LinkedList<T>::deletePos(int pos) {
    //copy the head pointer
    if(pos!=0) {
        Node<T> *minusOne = getValPos(pos - 1);
        //get the node at the position
        Node<T> *plusOne = getValPos(pos+1);
        //now make a connection
        minusOne->next =plusOne;
    }
    else{
        Node<T> *plusOne = getValPos(pos+1);
        head=plusOne;
    }
}

template <typename T>
void LinkedList<T>::insertPos(Node<T> *value, int pos) {
    //copy the head pointer
    if(pos!=0) {
        Node<T> *minusOne = getValPos(pos - 1);
        //get the node at the position
        Node<T> *atPos = getValPos(pos);
        //now make a connection
        minusOne->next = value;
        value->next = atPos;
    }
    else{
        Node<T> *atPos = getValPos(pos);
        head=value;
        value->next=atPos;
    }
}


template <typename T>
Node<T> *LinkedList<T>::getValPos(int pos) {
    //gets the position of a particular value
    //copy the value of the head
    Node<T> *current;
    int currPos=0;
    current=head;
    while(pos!=currPos){
        currPos++;
        current=current->next;
    }
    cout<<"the value at position "<< pos <<" is "<<current->value<<'\n';
    return current;
}

template <typename T>
int LinkedList<T>::getPos(T value) {
    //gets the position of a particular value
    //copy the value of the head
    Node<T> *current;
    int pos=0;
    current=head;
    while(current->next!=NULL){
        if(current->value==value){
            cout<<"position at "<<pos<<'\n';
            return pos;
        }
        pos++;
        current=current->next;
    }
}

template <typename T>
void LinkedList<T>::printList() {
Node<T> *current;
current=head;
    while(current->next!=NULL){
        cout<<current->value<<'\n';
        current=current->next;
    }
   cout<<current->value<<'\n';
}

//this method appends a value into the list like a stack.
template <typename T>
void LinkedList<T>::insert(Node<T> *node) {
    // make a copy
    //iterate till the current one points to a NULL
    Node<T> *current;
    current=head;
    //check for the head if its null then we address the case
    if(head!=NULL) {
        //while the next pointer points to a null just iterate.
        while (current->next!= NULL) {
            current = current->next;
        }
        current->next=node;
    }
    else {
        head=node;
    }
 }

int main(){
    //make a new linkedlist
    LinkedList<float> list;

    Node<float> *first= new Node<float>;
    Node<float> *second= new Node<float>;
    Node<float> *third= new Node<float>;
    Node<float> *fourth= new Node<float>;

    first->value=12.34;
    first->next=NULL;
    second->value=2.34;
    second->next=NULL;
    third->value=31.3434;
    third->next=NULL;
    fourth->value=45;
    fourth->next=NULL;
    list.insert(first);
    list.insert(second);
    list.insert(third);
    list.getValPos(2);
    list.getPos(2.34);
    list.insertPos(fourth,2);
    list.deletePos(2);
    list.printList();
}

