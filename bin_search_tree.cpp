#include <iostream>
#include <vector>
/*
 * Class representing a binary search tree
 */
using namespace std;

//creating a Node class

struct Node{
    int value;
    //pointer of type Node to point to left and right members
    Node *left;
    Node *right;
};

class BST{
    //a root of type Node
    Node *root;
public:
    explicit BST(Node *rootnode);
    ~BST();
    bool preorder_search(int val);
    void insert_helper(Node *rootval,int value);
    void insert(int value);
    bool preorder_helper(Node *rootnode,int value);
    void print_preorder();
    void print_preorder_helper(Node *rootval);
};

BST::BST(Node *rootnode) {
    root=rootnode;
}

bool BST::preorder_search(int val){
    //adds a node to the current BST
    //helper function compliments the search by starting at the root
    return preorder_helper(root,val);
}
bool BST::preorder_helper(Node *rootnode,int val) {
    //if the root is the value needed
    cout << rootnode->value << '\n';
    /*
     * Check the parent first and then recursively -
     * -search for right or left based on comparison with parent node
     */
    if (rootnode != NULL) {
        if (rootnode->value == val) {
            return true;
        }
        else if (val > rootnode->value && rootnode->right != NULL){
            return BST::preorder_helper(rootnode->right, val);
        }
         else if (val < rootnode->value && rootnode->left != NULL) {
            return BST::preorder_helper(rootnode->left, val);
        }
    }
    return false;
}

void BST::insert_helper(Node *rootval,int value) {
    //inserting value in the tree with the BST properties
    Node *addvalue = new Node;
    addvalue->value=value;
    addvalue->left=NULL;
    addvalue->right=NULL;
    //check if root exists
    if(rootval){
        //check if new value is lower or higher than root
        //add to left if lower, else right
        if(value>rootval->value){
            if(rootval->right==NULL){
                rootval->right=addvalue;
            }
            else {
                return BST::insert_helper(rootval->right, value);
            }
        }
        else{
            if(rootval->left==NULL){
                rootval->left=addvalue;
            }
            else{
                return BST::insert_helper(rootval->left,value);
            }
        }
    }

}

void BST::insert(int value) {
    BST::insert_helper(root,value);
}

void BST::print_preorder() {
    BST::print_preorder_helper(root);

}

void BST::print_preorder_helper(Node *rootval) {
    if(rootval){
        cout<<rootval->value<<'\n';
        BST::print_preorder_helper(rootval->left);
        BST::print_preorder_helper(rootval->right);
    }

}

BST::~BST() {
    cout<<"class destroyed";
}

int main(){
    cout<<"working!"<<'\n';
    Node *rootval=new Node;
    rootval->value=2;
    rootval->left=NULL;
    rootval->right=NULL;
    BST *bst=new BST(rootval);
    bst->insert(4);
    bst->insert(1);
    bst->insert(8);
    bst->print_preorder();
    cout<<bst->preorder_search(2);

}
