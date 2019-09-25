// Copyright 2019 Kartik Madhira
// Return Kth element form last of a linked list

#include <iostream>
#include <map>
#include "singly_linked_list.h"

template<typename T>
Node<T> intersection_2_ll(SinglyLinkedList<T> first_list, SinglyLinkedList<T> sec_list) {
    // Essentially create a map of <address> and a <int>
    // and then iterate over the first and second list
    // Create a map for the first list
    std::map<Node<T>*, int> address_mapping;
    Node<T> *temp = first_list.tail;
    while (temp != nullptr) {
        address_mapping[temp] = 1;
        temp = temp->next;
    }
    temp = sec_list.tail;
    while (temp != nullptr) {
        if (address_mapping.find(temp) != address_mapping.end()) {
            return temp;
        } else {
            temp = temp->next;
        }
    }
    temp = nullptr;
    return temp;
}

int main() {
SinglyLinkedList<int> list_1;
    list_1.insert(2);
    list_1.insert(3);
    list_1.insert(5);
    list_1.insert(3);
    int a = 5;
    list_1.insert(5);
    list_1.insert(3);
    list_1.insert(2);
    list_1.insert(2);

}