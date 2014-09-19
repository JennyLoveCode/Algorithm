/*
1. find least common ancestor of two nodes.
*/
#include <iostream>
using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;
    Node(){ }
    Node(int v) : val(v), left(NULL), right(NULL){ } 
};

Node* LCA(Node*, Node*, Node* );

int main(){
    Node* root = new Node(0);
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);
    
    root->left = n1;
    root->right = n2;
    n1->left = n3;
    n1->right = n4;
    n2->left = n5;
    
    cout<<LCA(root, n3, n4)->val<<endl;
    return 0;
}

Node* LCA(Node* root, Node* p, Node* q){
    //base case
    if(root ==  NULL) return NULL;
    if(root == p || root == q) return root;
    //recursive rule
    Node* left = LCA(root->left, p, q);
    Node* right = LCA(root->right, p, q);
    if(left && right) return root;
    return left ? left : right;
}