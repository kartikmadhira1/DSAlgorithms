#include <iostream>
#include <vector>

using namespace std;

class Heap{
    //array that'll be used to represent Heap structure
    vector <int> heap_arr;
    int parent(int child);
    int left(int parent);
    int right(int parent);
};
