/*
3. link and remove leave nodes

               0                ->           0
	        /     \                         /\                                          	
          1         2                     1    2                       	
         /\         /\                                                                    	
 	    3   4      5   6                3->4->5->6

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

struct ListNode{
    int val;
    ListNode* next;
    ListNode(){ }
    ListNode(int v): val(v), next(NULL){ }
};

Node* RemoveLink(Node* , vector<ListNode*> &);
void PrintTree(Node*);
void PrintList(vector<ListNode*>);

int main(){
    Node* root = new Node(0);
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);
    Node* n6 = new Node(6);
    Node* n7 = new Node(7);
    Node* n8 = new Node(8);
    
    root->left = n1;
    root->right = n2;
    n1->left = n3;
    n1->right = n4;
    n2->left = n5;
    n2->right = n6;
    n3->left = n7;
    n3->right = n8;
    
    vector<ListNode*> v;
    Node* remove = RemoveLink(root, v);
    cout<<"New Tree is :"<<endl;
    PrintTree(remove);
    cout<<"New List is :"<<endl;
    PrintList(v);
}

Node* RemoveLink(Node* root, vector<ListNode* > &v){
    //base case
    if(root == NULL) return NULL;
    if(root->left == NULL && root->right == NULL){
        ListNode* leave = new ListNode(root->val);
        v.push_back(leave);
        return NULL;
    }
    Node* l = RemoveLink(root->left, v);
    Node* r = RemoveLink(root->right, v);
    root->left = l;
    root->right = r;
    return root;
}

void PrintTree(Node* root){
    if(root == NULL) return;
    PrintTree(root->left);
    cout<<root->val<<endl;
    PrintTree(root->right);
}

void PrintList(vector<ListNode*> v){
    for(int i = 0; i < v.size(); i++){
        cout<<v[i]->val<<endl;
    }
}