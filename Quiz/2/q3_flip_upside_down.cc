/*
Q3： Given a binary tree where all the right nodes are leaf nodes, flip it upside down 
and turn it into a tree with left leaf nodes.
*/
#include <iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(NULL), right(NULL){ }
};

TreeNode* Flip(TreeNode* );
void Print(TreeNode* );

int main(){
    TreeNode root(0);
    TreeNode n1(1);
    TreeNode n2(2);
    TreeNode n3(3);
    TreeNode n4(4);
    
    root.left = &n1;
    root.right = &n2;
    n1.left = &n3;
    n1.right = &n4;
    
    Print(&root);
    TreeNode* new_root = Flip(&root);
    cout<<"========================"<<endl;
    Print(new_root);
    return 0;
}

TreeNode* Flip(TreeNode* root){
    if(root == NULL || root->left == NULL){
        return root;
    }
    TreeNode* new_root = Flip(root->left);
    root->left->left = root->right;
    root->left->right = root;
    root->left = NULL;
    root->right = NULL;
    return new_root;
}

void Print(TreeNode* root){
    if(root == NULL) return;
    Print(root->left);
    cout<<root->val<<endl;
    Print(root->right);
}