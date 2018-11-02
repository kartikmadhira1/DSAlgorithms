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
};

class Stack{
private:
    int stackSize=0;
public:
    Node *top=NULL;
    void push(int val);
    int pop();
    void printStack();
};

int Stack::pop() {
    Node *current=top;
    stackSize--;
    top=top->prev;
    return current->value;
}

void Stack::push(int val) {
    Node *value= new Node;
    value->value=val;
    Node *current=top;
    stackSize++;
    if(top!=NULL){
        //take a copy of top and point the prev of pushed to top!
        top=value;
        value->prev=current;
    }
    else{
        top=value;
    }
}

void Stack::printStack() {
    Node *current=top;
    for (int i=0;i<stackSize;i++){
        cout<<current->value<<'\n';
        current=current->prev;
    }
}

int main(){
    Stack stack=Stack();
    stack.push(3);
    stack.push(2);
    stack.push(2);
    stack.push(234);
    stack.push(2311222);
    stack.pop();
    stack.pop();
    stack.printStack();
}