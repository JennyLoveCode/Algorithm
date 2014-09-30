/*
1. find parent node of a given node in a binary tree.
*/
#include <iostream>
using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int v):val(v),left(NULL),right(NULL){ }
};

Node* FindParent(Node* , Node* , int );
Node* FindParentBST(Node* , Node* , int );

int main(){
    Node* root = new Node(8);
    Node* n3 = new Node(3);
    Node* n12 = new Node(12);
    Node* n1 = new Node(1);
    Node* n5 = new Node(5);
    Node* n9 = new Node(9);
    Node* n15 = new Node(15);
    
    root->left = n3;
    root->right = n12;
    n3->left = n1;
    n3->right = n5;
    n12->left = n9;
    n12->right = n15;
    
    //Node* parent = new Node(-1);

    Node* result1 = FindParent(root, NULL,5);
    Node* result2 = FindParentBST(root, NULL,5);
    if(result1 != NULL && result2 != NULL){
        cout<<"result 1 is "<<result1->val<<" result 2 is "<<result2->val<<endl; 
    }
    return 0;
}

Node* FindParent(Node* root, Node* parent, int target){
    //base case
    if(root == NULL){
        return NULL;
    }
    cout<<"cur root is "<<root->val<<endl;
    if(root->val == target){
        return parent;
    }
    Node* l = FindParent(root->left, root, target);
    //find target in left subtree
    if( l!=NULL ){
        return l;
    }
    Node* r = FindParent(root->right, root, target);
    return r;
}

/*
    find parent node of a given node in a binary search tree.
*/
Node* FindParentBST(Node* root, Node* parent, int target){
    if(root == NULL){
        return NULL;
    }
    cout<<"BST cur root is "<<root->val<<endl;
    if(root->val == target){
        return parent;
    }
    Node* l, *r = NULL;
    if(root->val > target){
        l = FindParent(root->left, root, target);
    }
    else{
        r = FindParent(root->right, root, target);
    }
    return l !=NULL ? l : r;
}