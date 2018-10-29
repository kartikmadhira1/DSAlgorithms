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
public:
    T value;
    Node<T> *next;
    Node(T val): value(val),next(NULL){}
};


