/*
Given a binary tree, find the maximum path sum.
The path may start and end at any node in the tree.
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

int MaxPath (TreeNode* root, int &max_sum);

int main () {
    TreeNode* n9 = new TreeNode(9);
    TreeNode* n2 = new TreeNode(2);
    TreeNode* n3 = new TreeNode(3);
    TreeNode* n5 = new TreeNode(5);
    TreeNode* n10 = new TreeNode(10);

    n9->left = n2;
    n9->right = n3;
    n2->left = n5;
    n2->right = n10;
    
    int max_sum = INT_MIN;
    int res = MaxPath(n9, max_sum);
    cout<<"Maximum path sum is "<<max_sum<<endl;
    return 0;
}

int MaxPath (TreeNode* root, int &max_sum) {
    if (root == NULL) {
        return 0;
    }
    int sum = root->val;
    int l = MaxPath(root->left, max_sum);
    int r = MaxPath(root->right, max_sum);
    if (l > 0) sum += l;
    if (r > 0) sum += r;
    max_sum = max(sum, max_sum);
    return max(l,r) > 0 ? max(l, r)+root->val : root->val;
}