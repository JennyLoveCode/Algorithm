/*
Reconstruct a tree, we give a preorder sequence, the array contains Nodes and null, null represents.
	[A, B, null, null, C, null, null],
				        A
			         /	   \
			      B      E 
              /    
             C      

 	[A, B, “C”,”null”, null, null, E, null, null]
	[A,  B   null(C),   null]
	[A, null(B) , E  null ,null]
	[A, null(B) ,null(E)];

	use, 
	stack
*/
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode () { }
    ~TreeNode () { }
    TreeNode (int v) : val(v), left(NULL), right(NULL) { }
};

TreeNode* Reconstruct (vector<TreeNode*> v);
void print(TreeNode* root);

int main () {
    TreeNode* n1 = new TreeNode(1);
    TreeNode* n2 = new TreeNode(2);
    TreeNode* n3 = new TreeNode(3);
    TreeNode* n4 = new TreeNode(4);

    vector<TreeNode*> v;
    v.push_back(n1);
    v.push_back(n2);    
    v.push_back(n4);    
    v.push_back(NULL);    
    v.push_back(NULL);    
    v.push_back(NULL);    
    v.push_back(n3);    
    v.push_back(NULL);    
    v.push_back(NULL);    

    TreeNode* root = Reconstruct(v);
    print(root);
    return 0;
}

TreeNode* Reconstruct (vector<TreeNode*> v) {
    stack<TreeNode*> s;
    TreeNode* root = NULL;

    for(int i = v.size()-1; i >=0; --i){
        if(v[i] != NULL){
            if (!s.empty()) {
                v[i]->left = s.top();
                s.pop();
            }
            if (!s.empty()) {
                v[i]->right = s.top();
                s.pop();
            }
        }
        s.push(v[i]);
    }
    
    root = s.top();
    return root;
}

void print(TreeNode* root){
    if(root == NULL){
        return;
    }
    cout<<root->val<<endl;
    print(root->left);
    print(root->right);
}