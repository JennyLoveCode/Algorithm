/*
2 Binary Search Tree, second largest node in this tree.

                             5
                         /        \  
                      1             9 
                       \          /   \
                         3      8      11

if 9 is the largest node of the original tree and 9 has left child,
if 9 does not have left sub tree.
if 9 is root and 9 is leaf. return null.
without parent node. homework 2.
*/
#include <iostream>
using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int v):val(v),left(NULL),right(NULL){}
};

Node* SecondLarge(Node* );

int main(){
    Node* n5 = new Node(5);
    Node* n1 = new Node(1);
    Node* n9 = new Node(9);
    Node* n3 = new Node(3);
    Node* n8 = new Node(8);
    Node* n11 = new Node(11);
    
    n5->left = n1;
    n5->right = n9;
    n1->right = n3;
    n9->left = n8;
    n9->right = n11;

    Node* second = SecondLarge(n5);  
    cout<<"second large node is "<<second->val<<endl;
    return 0;      
}

Node* SecondLarge(Node* root){
    //single node or NULL
    if(root == NULL || (root->left == NULL && root->right == NULL)){
        return NULL;
    }
    //go right subtree
    Node* cur = root;
    Node* parent = NULL;
    while(cur->right != NULL){
        parent = cur;
        cur = cur->right;
    }
    //if right most node does not have left child
    if(cur->left == NULL){
        return parent;
    }
    //right most node has left child
    else{
        while(cur->left != NULL){
            cur = cur->left;
        }
    }
    return cur;
}