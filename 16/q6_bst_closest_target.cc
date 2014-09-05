/*
Q6: (BST) Given a binary search tree, how to find the node with its value closest 
to a target value x?
*/
#include <iostream>
#include <stdlib.h>
using namespace std;

struct node{
    int val;
    node* left;
    node* right;
    node(int v):val(v), left(NULL), right(NULL){};
};

int find_closest(node* root, int target){
    if(root == NULL) return INT_MAX;
    node* cur = root;
    node* solution = root;
    int gap = abs(root->val - target);
    
    while(cur){
        if(target == cur->val) return cur->val;
        if(abs(cur->val - target) < gap){
            gap = abs(cur->val - target);
            solution = cur;
        }
        cur = target < cur->val ? cur->left : cur->right;
    }
    return solution->val;
}

int main(){
    node* root = new node(5);
    node* n1 = new node(3);
    node* n2 = new node(9);
    node* n3 = new node(1);
    node* n4 = new node(4);
    node* n5 = new node(8);
    node* n6 = new node(11);
    
    root->left = n1;
    root->right = n2;
    n1->left = n3;
    n1->right = n4;
    n2->left = n5;
    n2->right = n6;
    
    int target = 6;
    int result = find_closest(root, target);
    cout<<result<<endl;
    return 0;
}