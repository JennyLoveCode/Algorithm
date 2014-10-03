/*
Binary Tree / Binary Search Tree serialization/deserialization.
binary search tree, pre/post order, reconstruct.
binary tree, inorder + pre/post
binary tree, layer by layer reconstruct
binary tree, pre/post order.
*/
#include <iostream>
#include <string>
#include <queue>
using namespace std;

struct Node{
    char val;
    Node* left;
    Node* right;
    Node(char v): val(v), left(NULL), right(NULL){}
};

Node* ReconstructPre(string , int , int );
Node* ReconstructLevel(string );
void Print(Node* );

int main(){
    string pre = "310##2##54##6##";
    Node* root = ReconstructPre(pre, 0, pre.size()-1);
    Print(root);
    
    string s = "517#368#####9##";
    Node* result = ReconstructLevel(s);
    cout<<"==================="<<endl;
    Print(result);
    return 0;
}

Node* ReconstructPre(string pre, int begin, int end){
    //base case
    if(begin+1 >= end){
        return NULL;
    }
    Node* root = new Node(pre[begin]);
    root->left = ReconstructPre(pre, begin+1, begin+(end-begin)/2);
    root->right = ReconstructPre(pre, begin+(end-begin)/2+1, end);
    return root;
}

Node* ReconstructLevel(string s){
    Node* root = new Node(s[0]);
    queue<Node*> q;
    //store nodes in previous level
    q.push(root);
    int i = 1;    
    while(!q.empty()){
        Node* cur = q.front();
        q.pop();
        if(s[i] == '#'){
            cur->left = NULL;
            i++;
        }
        else{
            cur->left = new Node(s[i++]); 
            q.push(cur->left);
        }
        if(s[i] == '#'){
            cur->right = NULL;
            i++;
        }
        else{
            cur->right = new Node(s[i++]); 
            q.push(cur->right);
        }
    }
    return root;
}

//inorder print
void Print(Node* root){
    if(root == NULL){
        return;
    }
    Print(root->left);
    cout<<root->val<<endl;
    Print(root->right);
}