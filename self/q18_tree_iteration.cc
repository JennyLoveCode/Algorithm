/*
inorder preorder postorder
*/
#include <iostream>
#include <stack>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode () { }
    ~TreeNode () { }
    TreeNode (int v) : val(v), left(NULL), right(NULL) {}
};

void preorder (TreeNode* root);
void preorder_r (TreeNode* root);
void inorder (TreeNode* root);
void inorder_r (TreeNode* root);
void postorder (TreeNode* root);
void postorder_r (TreeNode* root);

int main () {
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

    //cout<<"preorder ============ "<<endl;
    //preorder(root);
    //cout<<"inorder  ============ "<<endl;
    //inorder(root);
    cout<<"postorder ============ "<<endl;
    postorder(root);
    cout<<endl;
    //preorder_r(root);
    //inorder_r(root);
    postorder_r(root);
    return 0;
}

void preorder (TreeNode* root) {
    if (root == NULL) {
        return;
    }
    stack<TreeNode*> s;
    TreeNode* cur = root;
    while (cur || !s.empty()) {
        if (cur) {
            cout<<cur->val<<endl;
            s.push(cur);
            cur = cur->left;
        } else {
            cur = s.top();
            s.pop();
            cur = cur->right;
        }
    }
    return;
}

void inorder (TreeNode* root) {
    if (root == NULL) {
        return;
    }
    stack<TreeNode*> s;
    TreeNode* cur = root;
    while (cur || !s.empty()) {
        if (cur) {
            s.push(cur);
            cur = cur->left;
        } else {
            cur = s.top();
            cout<<cur->val<<endl;
            s.pop();
            cur = cur->right;
        }
    }
    return;
}

void postorder (TreeNode* root) {
    if (root == NULL) {
        return;
    }
    stack<TreeNode*> s;
    s.push(root);
    TreeNode* prev = NULL;
    while (!s.empty()) {
        TreeNode* cur = s.top();
        //traverse down
        if (!prev || prev->left == cur || prev->right == cur) {
            if (cur->left) {
                s.push(cur->left);
            } else if (cur->right) {
                s.push(cur->right);
            }
        } else if (cur->left == prev) { //traverse up from left child
            if (cur->right) {
                s.push(cur->right);
            }
        } else {
            cout<<cur->val<<endl;
            s.pop();
        }
        prev = cur;
    }
}

void preorder_r (TreeNode* root) {
    if (root == NULL) {
        return;
    }
    cout<<root->val<<endl;
    preorder_r(root->left);
    preorder_r(root->right);
}

void inorder_r (TreeNode* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    cout<<root->val<<endl;
    inorder(root->right);
}

void postorder_r (TreeNode* root) {
    if (root == NULL) {
        return;
    }
    postorder_r(root->left);
    postorder_r(root->right);
    cout<<root->val<<endl;
}