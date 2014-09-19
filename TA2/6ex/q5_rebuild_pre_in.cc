/*
5. given preorder sequence and inorder sequence reconstruct the binary tree.
*/
#include <iostream>
#include <vector>
using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;
    Node(){ }
    Node(int v): val(v), left(NULL), right(NULL){ }
};

Node* Build(vector<Node*> &, int , int , vector<Node*> &, int , int );
int FindRootPos(vector<Node*> &, int , int , int );
void Print(Node* );

int main(){
    Node* root = new Node(0);
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);
    Node* n6 = new Node(6);
    
    vector<Node*> pre;
    pre.push_back(root);
    pre.push_back(n1);
    pre.push_back(n3);
    pre.push_back(n4);
    pre.push_back(n2);
    pre.push_back(n5);
    pre.push_back(n6);
    
    vector<Node*> in;
    in.push_back(n3);
    in.push_back(n1);
    in.push_back(n4);
    in.push_back(root);
    in.push_back(n5);
    in.push_back(n2);
    in.push_back(n6);

    Node* result = Build(pre, 0, 6, in, 0, 6);
    cout<<"Pre-order is "<<endl;
    Print(result);
    return 0;
}

Node* Build(vector<Node*> &pre, int pre_start, int pre_end, vector<Node*> &in, int in_start, int in_end){
    Node* root = pre[pre_start];
    //base case: arrive in leaves
    if(pre_start == pre_end) return root;
    if(in_start == in_end) return root;
    //recursive rule
    int root_pos = FindRootPos(in, in_start, in_end, root->val);
    int left_len = root_pos - in_start;
    root->left = Build(pre, pre_start+1, pre_start+left_len, in, in_start, root_pos-1);
    root->right = Build(pre, pre_start+left_len+1, pre_end, in, root_pos+1, in_end);
    return root;
}

int FindRootPos(vector<Node*> &v, int start, int end, int target){
    for(int i = start; i <= end; i++){
        if(v[i]->val == target){
            return i;
        }
    }
    return -1;
}

void Print(Node* root){
    if(root == NULL) return;
    cout<<root->val<<endl;
    Print(root->left);
    Print(root->right);
    return;
}





