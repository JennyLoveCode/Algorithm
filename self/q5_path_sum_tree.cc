/*
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the 
values along the path equals the given sum.
*/
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode () { }
    ~TreeNode () { }
    TreeNode (int v) : val(v), left(NULL), right(NULL){}
};

bool HasSum (TreeNode* root, int sum);
void FindAllPath(TreeNode* root, int sum, vector<TreeNode*> &path);
void print(vector<TreeNode*> &v);

int main () {
    TreeNode* n5 = new TreeNode(5);
    TreeNode* n4 = new TreeNode(4);
    TreeNode* n8 = new TreeNode(8);
    TreeNode* n15 = new TreeNode(15);
    TreeNode* n13 = new TreeNode(13);
    TreeNode* n6 = new TreeNode(6);
    TreeNode* n1 = new TreeNode(1);
    TreeNode* n2 = new TreeNode(2);
    TreeNode* n7= new TreeNode(7);

    n5->left = n4;
    n5->right = n8;
    n4->left = n15;
    n8->left = n13;
    n8->right = n6;
    n15->left = n7;
    n15->right = n2;
    n6->right = n1;
    
    int sum = 26;
    /*
    bool res = HasSum(n5, sum);
    if (res) {
        cout<<"true"<<endl;
    } else {
        cout<<"false"<<endl;
    }
    */
    vector<TreeNode*> path;
    FindAllPath(n5, sum, path);
    return 0;
}

bool HasSum (TreeNode* root, int sum) {
    if (root == NULL) {
        return false;
    }
    if (root->val == sum && root->left == NULL && root->right == NULL) {
        return true;
    }
    return HasSum(root->left, sum-root->val) || HasSum(root->right, sum-root->val);
}

void FindAllPath(TreeNode* root, int sum, vector<TreeNode*> &path){
    if (root == NULL) {
        return;
    }
    if (root->val == sum && root->left == NULL && root->right == NULL) {
        path.push_back(root);
        print(path);
        path.pop_back();
        return;
    }
    path.push_back(root);
    FindAllPath(root->left, sum-root->val, path);
    FindAllPath(root->right, sum-root->val, path);
    path.pop_back();
}


void print(vector<TreeNode*> &v){
    for (int i = 0; i < v.size(); ++i) {
        cout<<v[i]->val<<" ";
    }
    cout<<endl;
}