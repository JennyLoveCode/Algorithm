/*
Q4: (Tree) How to print the value of all nodes in a binary tree layer by layer.
*/
#include <iostream>
#include <queue>
using namespace std;

struct node{
    int val;
    node* left;
    node* right;
    node(int v): val(v), left(NULL), right(NULL){}
};

void swap(int &a, int &b){
    int tmp = a;
    a = b;
    b = tmp;
    return;
}

void print_by_layer(node* root){
    if(root == NULL) return;
    queue<node*> q;
    q.push(root);

    int cur_layer = 1;
    int next_layer = 0;    
    while(!q.empty()){
        while(cur_layer > 0){
            node* cur = q.front();
            cout<<cur->val<<" ";
            q.pop();
            cur_layer--;
            
            if(cur->left){
                q.push(cur->left);
                next_layer++;
            }
            if(cur->right){
                q.push(cur->right);
                next_layer++;
            }
        }
        cout<<endl;
        swap(cur_layer, next_layer);
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
    
    print_by_layer(root);
    return 0;
}