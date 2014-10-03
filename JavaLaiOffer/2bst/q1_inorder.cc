/*
    In-order traversal
    
                             5
                         /        \  
                    1              9 
                       \          /    \
                         3      8     11

*/
#include <iostream>
using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int v):val(v),left(NULL),right(NULL){}
};

void Inorder(Node* );

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
    
    Inorder(n5);
    return 0;
}

void Inorder(Node* root){
    if(root == NULL){
        return;
    }
    Inorder(root->left);
    cout<<root->val<<endl;
    Inorder(root->right);
}