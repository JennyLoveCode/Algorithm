/*
Given a root, node A and node B of a BST, assume A.key < B.key, find the least 
common ancestor.
*/
#include <iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode () { }
    ~TreeNode () { }
    TreeNode (int v) : val(v), left(NULL), right(NULL) {}
};

TreeNode* Ancestor (TreeNode* root, TreeNode* p, TreeNode* q);

int main () {
    TreeNode* root = new TreeNode(15);
    TreeNode* n7 = new TreeNode(7);
    TreeNode* n18 = new TreeNode(18);
    TreeNode* n4 = new TreeNode(4);
    TreeNode* n10 = new TreeNode(10);
    TreeNode* n3 = new TreeNode(3);
    TreeNode* n5 = new TreeNode(5);
    TreeNode* n8 = new TreeNode(8);
    TreeNode* n11 = new TreeNode(11);

    root->left = n7;
    root->right = n18;
    n7->left = n4;
    n7->right = n10;
    n4->left = n3;
    n4->right = n5;
    n10->left = n8;
    n10->right = n11;
    
    TreeNode* res = Ancestor(root, n8, n11);
    cout<<res->val<<endl;
    return 0;
}

TreeNode* Ancestor (TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == NULL) {
        return NULL;
    }
    if (p->val <= root->val && root->val <= q->val) { 
        return root;   
    } else if (root->val > q->val) {
        return Ancestor(root->left, p, q);
    } else {
        return Ancestor(root->right, p, q);
    }
}