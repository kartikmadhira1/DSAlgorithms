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
    Node<T> *next;
};

//define a class of Linkedlist that runs on the simple nodes
template <typename T>
class LinkedList{
public:
    //will this be a pointer?
    Node<T> *head;
    Node<T> *tail;
    void insert(Node<T> *node);
    void printList();
};

template <typename T>
void LinkedList<T>::printList() {
Node<T> *current= new Node<T>;
    while(head->next!=NULL){
        cout<<current->value<<'\n';
        current=current->next;
    }
   cout<<current->value<<'\n';
}

template <typename T>
void LinkedList<T>::insert(Node<T> *node) {
    // make a copy
    //iterate till the current one points to a NULL
    Node<T> *current = new Node<T>;
    current=head;
    while(current->next!=NULL){
        current=current->next;
    }
    current->next=node;
}

int main(){
    //make a new linkedlist
    LinkedList<float> list;

    Node<float> *first= new Node<float>;
    Node<float> *second= new Node<float>;
    Node<float> *third= new Node<float>;

    first->value=12.34;
    first->next=NULL;

    second->value=2.34;
    second->next=NULL;

    third->value=31.3434;
    third->next=NULL;

    list.insert(first);
    list.insert(second);
    list.insert(third);
    list.printList();
}


