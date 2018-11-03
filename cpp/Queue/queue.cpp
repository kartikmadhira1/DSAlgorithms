#include <iostream>

/*
 * Methods:
 * 1. push
 * 2. pop
 * 3. isEmpty
 */
using namespace std;

class Node{
public:
    //using a slighly different Node with a prev value
    int value=0;
    Node *prev=NULL;
    Node *next=NULL;
};

class Queue{
private:
    int queueSize=0;
public:
    Node *head;
    Node *tail;
    void enqueue(int val);
    int dequeue();
    void printQueue();
};

void Queue::enqueue(int val) {
    Node *value= new Node();
    value->value=val;
    queueSize++;
    if(queueSize!=1) {
        Node *prev = tail;
        tail = value;
        value->next = prev;
    }
    else{
        tail=value;
        head=value;
    }
}

void Queue::printQueue() {
    Node *current=tail;
    for(int i=0;i<queueSize;i++){
        cout<<current->value<<"\n";
        current=current->next;
    }
}

int Queue::dequeue() {
    queueSize--;
    Node *current=head;
    if(queueSize!=0){
        head=head->prev;
        return current->value;
    }
    else{
        head=NULL;
        cout<<"The queue has become empty!"<<'\n';
    }
}

int main (){
    Queue queue=Queue();
    queue.enqueue(5);
    queue.enqueue(5);
    queue.enqueue(3);
    queue.enqueue(2);
    queue.printQueue();
    queue.enqueue(223);
    queue.enqueue(223);
    queue.dequeue();
    queue.printQueue();
}
