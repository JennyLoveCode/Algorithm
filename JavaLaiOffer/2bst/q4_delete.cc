/*
Binary Search Tree, keep nodes in the  range of [MIN, MAX], 
                            5
                         /        \  
                    1              9 
                       \           /  \
                         3       8    11

[MIN, MAX] = [2, 8]
*/
#include <iostream>
using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int v):val(v),left(NULL),right(NULL){}
};

Node* KeepRange(Node* root, int , int);
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
    
    int low = 3;
    int high = 5;
    Print(n5);
    Node* result = KeepRange(n5, low, high);
    cout<<"keep result from "<<low<<" to "<<high<<" is "<<endl;
    Print(n5);
    return 0;
}

Node* KeepRange(Node* root, int low, int high){
    if(root == NULL){
        return NULL;
    }
    //discard left subtree
    if(root->val < low){
        return KeepRange(root->right, low, high);
    }
    //discard right subtree
    else if(root->val > high){
        return KeepRange(root->left, low, high);
    }
    //keep nodes in the range of [min, max]
    else{
        root->left = KeepRange(root->left, low, high);
        root->right = KeepRange(root->right, low, high);
        return root;
    }
}

void Print(Node* root){
    if(root == NULL){
        return;
    }
    Print(root->left);
    cout<<root->val<<endl;
    Print(root->right);
}
