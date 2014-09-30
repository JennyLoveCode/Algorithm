/*
2 create mirror of a given binary tree.
*/
#include <iostream>
using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int v):val(v),left(NULL),right(NULL){ }
};

Node* Mirror(Node* );
void Print(Node* );

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
    
    Node* new_root = Mirror(root);
    Print(root);
    cout<<"=========================="<<endl;
    Print(new_root);
    return 0;
}

Node* Mirror(Node* root){
    if(root == NULL){
        return NULL;
    }
    Node* new_node = new Node(root->val);
    new_node->left = Mirror(root->right);
    new_node->right = Mirror(root->left);
    return new_node;
}

void Print(Node* root){
    if(root == NULL){
        return;
    }
    Print(root->left);
    cout<<root->val<<endl;
    Print(root->right);
}