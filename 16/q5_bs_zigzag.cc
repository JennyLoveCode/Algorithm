/*
Q5 (Tree) How to print the value of all nodes in a binary tree in a zigzag way?
*/
#include <iostream>
#include <stack>
using namespace std;

struct node{
    int val;
    node* left;
    node* right;
    node(int v): val(v), left(NULL), right(NULL){};
};

void bs_zigzag(node* root){
    if(root == NULL) return;
    stack<node*> cur, next;
    cur.push(root);
    bool order = true;
    while(!cur.empty()){
        while(!cur.empty()){
            node* cur_node = cur.top();
            cur.pop();
            cout<<cur_node->val<<" ";
            if(order){
                if(cur_node->left) next.push(cur_node->left);
                if(cur_node->right) next.push(cur_node->right);
            }
            else{
                if(cur_node->right) next.push(cur_node->right);
                if(cur_node->left) next.push(cur_node->left);
            }
        }
        cout<<endl;
        swap(cur, next);
        order = !order;
    }
}

int main(){
    node* root = new node(0);
    node* n1 = new node(1);
    node* n2 = new node(2);
    node* n3 = new node(3);
    node* n4 = new node(4);
    node* n5 = new node(5);
    node* n6 = new node(6);
    
    root->left = n1;
    root->right = n2;
    n1->left = n3;
    n1->right = n4;
    n2->left = n5;
    n2->right = n6;
    
    bs_zigzag(root);
    return 0;  
}