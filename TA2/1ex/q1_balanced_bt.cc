/*
1. Judge whether a binary tree is Balanced or not?
*/
#include <iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(){ }
    TreeNode(int v): val(v), left(NULL), right(NULL){ }
};

bool IsBalanced(TreeNode* );
int GetMaxHeight(TreeNode* );

int main(){
    TreeNode* root = new TreeNode(0);
    TreeNode* n1 = new TreeNode(1);
    TreeNode* n2 = new TreeNode(2);
    TreeNode* n3 = new TreeNode(3);
    TreeNode* n4 = new TreeNode(4);
    TreeNode* n5 = new TreeNode(5);
    TreeNode* n6 = new TreeNode(6);
    
    root->left = n1;
    //root->right = n2;
    //n1->left = n3;
    n1->right = n4;
    //n2->left = n5;
    //n2->right = n6;
    
    if(IsBalanced(root)){
        cout<<"True"<<endl;
    }
    else{
        cout<<"False"<<endl;
    }
    return 0;
}

bool IsBalanced(TreeNode* root){
    int height = GetMaxHeight(root);
    return height > 0;
}

int GetMaxHeight(TreeNode* root){
    //base case
    if(root == NULL) return 0;
    //recursive rule
    int l = GetMaxHeight(root->left);
    int r = GetMaxHeight(root->right);
    if(abs(l-r) > 1) return -1;
    else{
        return max(l,r)+1;    
    }
}