#include <iostream>
#include <vector>

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
    void insert(int value);
    void insert_helper(Node *rootval,int value);
    bool preorder_search(int val);
    bool preorder_helper(Node *rootnode,int value);
    bool inorder_search(int val);
    bool inorder_search_helper(Node *rootnode,int val);
    void print_preorder();
    void print_preorder_helper(Node *rootval);
    void print_tree();
    void print_tree_helper(Node *rootval);
};

BST::BST(Node *rootnode) {
    root=rootnode;
}

//preorder sees the parent first and checks it off
//every recusrisive iteration checks only the parent,
//and every recusive call is for the leaf nodes.
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

//inorder search checks off every left node and then traverses to the right.
bool BST::inorder_search(int val) {
    return BST::inorder_search_helper(root,val);

}

bool BST::inorder_search_helper(Node *rootnode, int val) {
    //check the left leaf of parent, if exists, move to the leaf.
    cout<<rootnode->value<<'\n';
    if(rootnode->left!=NULL) {
        if (rootnode->left->left != NULL || rootnode->left->right != NULL) {
            if (rootnode->left->value == val) {
                return true;
            }
            return BST::inorder_search_helper(rootnode->left, val);
        } else {
            if (rootnode->left->value == val) {
                return true;
            }
        }
    }
    if(rootnode->right!=NULL) {
        if (rootnode->right->right != NULL || rootnode->right->left != NULL) {


            if (rootnode->right->value == val) {
                return true;
            }
            return BST::inorder_search_helper(rootnode->right, val);
        } else {

            if (rootnode->right->value == val) {
                return true;
            }
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

void BST::print_tree(){
    BST::print_tree_helper(root);
}

void BST::print_tree_helper(Node *rootval){
    cout<<"parent is:"<<rootval->value<<'\n';
    if(rootval->left!=NULL) {
        cout << "left Node is:" << rootval->left->value << '\t';
    }
    else{
        cout << "left Node is: NULL"<<'\t';
    }
    if(rootval->right!=NULL) {
        cout << "right Node is:" << rootval->right->value << '\n';
    }
    else{
        cout << "right Node is: NULL" <<'\n';
    }
    cout<<"-----------------------"<<'\n';
    if(rootval->left!=NULL){
        BST::print_tree_helper(rootval->left);
    }
    if(rootval->right!=NULL){
        BST::print_tree_helper(rootval->right);
    }
}


BST::~BST() {
    cout<<"class destroyed";
}

int main(){
    cout<<"working!"<<'\n';
    Node *rootval=new Node;
    rootval->value=190;
    rootval->left=NULL;
    rootval->right=NULL;
    BST *bst=new BST(rootval);
    bst->insert(2);
    bst->insert(199);
    bst->insert(12);
    bst->insert(15);
    bst->insert(10);
    bst->print_tree();
    cout<<bst->inorder_search(10);

}