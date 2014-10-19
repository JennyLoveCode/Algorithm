/*
Q1  Check if two nodes are cousins in a Binary Tree
Given the binary Tree and the two nodes say ‘a’ and ‘b’, determine whether the two nodes are 
cousins of each other or not.
Two nodes are cousins of each other if they are at same level and have different parents.
*/

/*same height from root to node
find lowest common ancestor, !(lca->right == a && lca->left == b)
*/

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode () { }
    ~TreeNode () { }
    
    TreeNode(int v): val(v), left(NULL), right(NULL) { }
};

bool IsCousin(TreeNode* root, TreeNode* a, TreeNode* b);
int GetHeight (TreeNode* root, TreeNode* a, int h);
TreeNode* LCA (TreeNode* root, TreeNode* a, TreeNode* b);

int main(){
    TreeNode* root = new TreeNode(0);
    TreeNode* n1 = new TreeNode(1);
    TreeNode* n2 = new TreeNode(2);
    TreeNode* n3 = new TreeNode(3);
    TreeNode* n4 = new TreeNode(4);
    TreeNode* n5 = new TreeNode(5);
    TreeNode* n6 = new TreeNode(6);
    
    root->left = n1;
    root->right = n2;
    n1->left = n3;
    n1->right = n4;
    n2->left = n5;
    n2->right = n6;

    bool res = IsCousin(root, n3, n5);
    if (res) {
        cout<<"True"<<endl;
    } else {
        cout<<"False"<<endl;
    }
    return 0;
}

bool IsCousin (TreeNode* root, TreeNode* a, TreeNode* b) {
    int h1 = GetHeight(root, a, 0);
    int h2 = GetHeight(root, b, 0);
    if (h1 != h2) {
        return false;
    }
    TreeNode* lca = LCA(root, a, b);
    if (lca->left == a && lca->right == b) {
        return false;
    }
    return true;
}

int GetHeight (TreeNode* root, TreeNode* a, int h) {
    //base case
    if(root == NULL){
        return 0;
    }
    if(root == a){
        return h;
    }

    //recursive rule
    int l = GetHeight(root->left, a, h+1);
    int r = GetHeight(root->right, a, h+1);
    return max(l, r);
}

TreeNode* LCA (TreeNode* root, TreeNode* a, TreeNode* b) {
    if (root == NULL) {
        return NULL;
    }
    if (root == a || root == b) {
        return root;
    }
    TreeNode* l = LCA(root->left, a, b);
    TreeNode* r = LCA(root->right, a, b);
    if (l && r) {
        return root;
    }
    return l ? l :r;
}