/*
Q26. (BST) Find the k-th largest element in BST
*/
#include <iostream>
#include <stack>
using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;
    Node(){ }
    Node(int v): val(v), left(NULL), right(NULL){}
};

int FindKthBST(Node* , int);

int main(){
    Node* root = new Node(5);
    Node* n3 = new Node(3);
    Node* n8 = new Node(8);
    Node* n1 = new Node(1);
    Node* n4 = new Node(4);
    Node* n7 = new Node(7);
    Node* n9 = new Node(9);
    //1 3 4 5 7 8 9 
    root->left = n3;
    root->right = n8;
    n3->left = n1;
    n3->right = n4;
    n8->left = n7;
    n8->right = n9;
    
    int k = 3;
    int result = FindKthBST(root, k);
    cout<<result<<endl;
    return 0; 
}

int FindKthBST(Node* root, int k){
    if(root == NULL) return INT_MAX;
    int count = k;
    stack<Node*> s;
    Node* cur =root;
    while(true){
        while(cur!= NULL){
            s.push(cur);
            cout<<"push "<<cur->val<<endl;
            cur = cur->right;
        }
        if(!s.empty()){
            cur = s.top();
            cout<<"pop "<<cur->val<<endl;
            s.pop();
            count--;
            if(count == 0)
                break;
            cur = cur->left;
        }
        else{
            cout<<"Error"<<endl;
            break;
        }
    }
    return cur->val;
}

/*
use stack to help to iterate bst in right root left order
*/

