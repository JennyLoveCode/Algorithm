/*
Q25, Determine whether a binary tree is complete binary tree.
  10
  5 15
2 7 12 20
1 null
*/
#include <iostream>
#include <queue>
using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;
    Node(){ }
    Node(int v): val(v), left(NULL), right(NULL){}
};

bool IsCompleted(Node* root);

int main(){
    Node* root = new Node(0);
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);
    
    root->left = n1;
    //root->right = n2;
    n1->left = n3;
    n1->right = n4;
    //n2->left = n5;

    bool result = IsCompleted(root);
    if(result) cout<<"True"<<endl;
    else cout<<"False"<<endl;
    return 0;
}

bool IsCompleted(Node* root){
    if(root == NULL) return true;
    queue<Node*> q;
    q.push(root);
    //flag to indicate the level is not full
    bool non_full = false;
    while(!q.empty()){
        Node* cur = q.front();
        q.pop();
        //check left child
        if(cur->left){
            if(non_full) return false;
            q.push(cur->left);
        }
        else{
            non_full = true;
        }
        //check right child
        if(cur->right){
            if(non_full) return false;
            q.push(cur->right);
        }
        else{
            non_full = true;
        }
    }
    return true;
}
