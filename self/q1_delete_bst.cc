/*
1. Delete a node in binary search tree.
                            5
                         /        \  
                    1              9 
                       \           /  \
                         3       8    11
*/
#include <iostream>
using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int k):val(k), left(NULL), right(NULL){ }
};

Node* Delete(Node* , int );
Node* MaxLeft(Node* );
void Print(Node* );

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
    
    int key = 1;
    Node* result = Delete(n5, key);
    Print(n5);
    return 0;
}

Node* Delete(Node* root, int key){
    if(root == NULL){
        return NULL;
    }
    //delete node lies in right subtree
    if(root->val < key){
        root->right = Delete(root->right, key);
    }
    //delete node lies in left subtree
    else if(root->val > key){
        root->left = Delete(root->left, key);
    }
    else{
        if(root->left == NULL){
            Node* tmp = root->right;
            delete root;
            return tmp;
        }
        else if(root->right == NULL){
            Node* tmp = root->left;
            delete root;
            return tmp;
        }
        else{
            Node* tmp = MaxLeft(root->left);
            root->val = tmp->val;
            root->left = Delete(root->left, tmp->val);
        }
    }
    return root;
}

Node* MaxLeft(Node* root){
    Node* cur = root;
    while(cur->right != NULL){
        cur = cur->right;
    }
    return cur;
}

void Print(Node* root){
    if(root == NULL){
        return;
    }
    Print(root->left);
    cout<<root->val<<endl;
    Print(root->right);
}
