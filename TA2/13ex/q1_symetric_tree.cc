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

bool IsSymmetric (TreeNode* p, TreeNode* q);

int main () {
    TreeNode* root1 = new TreeNode(0);
    TreeNode* root2 = new TreeNode(0);
    
    TreeNode* n1 = new TreeNode(1);
    TreeNode* n2 = new TreeNode(2);
    TreeNode* n3 = new TreeNode(3);

    TreeNode* n4 = new TreeNode(1);
    TreeNode* n5 = new TreeNode(2);
    TreeNode* n6 = new TreeNode(3);
    
    root1->left = n1;
    root1->right = n2;
    n1->left = n3;
    
    root2->left = n4;
    root2->right = n5;
    n4->right = n6;
    
    bool res = IsSymmetric(root1, root2);
    if (res) {
        cout<<"T"<<endl;
    } else {
        cout<<"F"<<endl;
    }
    cout<<INT_MAX<<endl;
    return 0;
}

bool IsSymmetric (TreeNode* p, TreeNode* q) {
    //base case
    if (p == NULL && q == NULL) {
        return true;
    } else if (p == NULL || q == NULL) {
        return false;
    }
    //recursive rule
    return p->val == q ->val &&
        IsSymmetric(p->left, q->left) &&
        IsSymmetric(p->right, q->right);    
}