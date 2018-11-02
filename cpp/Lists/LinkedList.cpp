#include <iostream>

/* Methods to Linked List object
 * - Insert
 * - Get Position
 * - insert at a position
 * - Delete from a position
 */

using namespace std;

struct Element{
    int value;
    //pointer pointing to a address with a DS with Element data type
    struct Element *next;

};

class LinkedList{
    Element *head;
public:
     LinkedList();
    ~LinkedList();
    void insert(Element *value);
    Element* get_position(int pos);
    void insert_at_pos(Element *value,int pos);
    void printList();

};

LinkedList::LinkedList() {
    //cout<<"lololol";
    head=NULL;
}

LinkedList::~LinkedList() {
    cout << "destroyed";
}

//method appends a value at the end of a linkedlist
void LinkedList::insert(Element *value) {
    Element * current=new Element;
    current=head;
    //if the head is not empty, traverse through linked list and append at the end
    if(head!=NULL){
        while (current->next!= NULL){
            //cout<<current->next;
            current=current->next;
        }
        current->next=value;
    }
    else{
        head=value;
    }
}

//get_position is a helper function for inserting a value a particular location
//this gets the value of the element present at a particular location
Element* LinkedList::get_position(int pos) {
    int position=1;
    //if the value is less than 1, just return NULL
    if(pos<1){
        return NULL;
    }
    else{
         Element *current=head;
        while(current!=NULL){
            if(position==pos){
                return current;
            }
            position++;
            current=current->next;
        }
    }
    //return 0;
    return NULL;
}

//this method adds a value to a particular position
void LinkedList::insert_at_pos(struct Element *value,int pos) {
    //struct Element *current=head;
    //making a previous and next member object
    struct Element *prev_mem=LinkedList::get_position(pos-1);
    struct Element *next_mem=LinkedList::get_position(pos);
    prev_mem->next=value;
    value->next=next_mem;
}


void LinkedList::printList() {
    struct Element * current;
    current=head;
    while(current!= NULL){
        cout<<current->value<<'\n';
        current=current->next;
    }
    //cout<<current->value;
}

int main() {
    //cout<<"new_Value";
    LinkedList list;
    Element *first= new Element;
    Element *second= new Element;
    Element *third= new Element;
   //delete first;
   second->value=123;
   second->next= NULL;

   third->value=1243;
   third->next= NULL;

   first->value=12493;
   first->next= NULL;

   list.insert(second);
   list.insert(first);
   list.insert(third);

   list.printList();
   cout<<"--------------------------------"<<'\n';
   //cout<<"getting position"<<'\n';
   //cout<<list.get_position(2)<<'\n';

   Element *fourth= new Element;
   cout<<"--------------------------------"<<'\n';
   cout<<"adding at position"<<'\n';

   list.insert_at_pos(fourth,3);
   list.printList();
    return 0;
}
