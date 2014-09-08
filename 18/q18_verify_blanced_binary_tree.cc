/*
Q18. Determine whether a binary tree is balanced or not (recursion).
*/
#include <iostream>
#include <stdlib.h>
using namespace std;

struct node{
    int val;
    node* left;
    node* right;
    
    node(){}
    node(int v) : val(v), left(NULL), right(NULL){}
};

int get_height(node* );
bool check_balanced(node* );

int get_height(node* root){
    //base case
    if(root == NULL) return 0;
    //recursive rule
    int left = get_height(root->left);
    int right = get_height(root->right);
    //check
    if(left < 0 || right < 0 || abs(left-right) > 1){
        return -1;
    }
    return max(left, right)+1;
}

bool check_balanced(node* root){
    return get_height(root) >= 0;
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
    //root->right = n2;
    n1->left = n3;
    n1->right = n4;
    //n2->left = n5;
    //n2->right = n6;
    
    cout<<check_balanced(root)<<endl;
    return 0;
}








