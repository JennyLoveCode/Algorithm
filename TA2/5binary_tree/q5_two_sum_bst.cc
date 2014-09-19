/*
5. Find a pair equal to the given sum in a Balanced BST, return boolean if exists.
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

void InOrderIterate(Node* , vector<int> &);
void Print(vector<int> );
void TwoSum(vector<int> , int);

int main(){
    Node* n0 = new Node(0);
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* root = new Node(4);
    Node* n5 = new Node(5);
    Node* n6 = new Node(6);
    Node* n7 = new Node(7);
    Node* n8 = new Node(8);
    
    root->left = n3;
    root->right = n5;
    n3->left = n1;
    n1->left = n0;
    n1->right = n2;
    n5->right = n7;
    n7->left = n6;
    n7->right = n8;
    
    int target = 8;
    vector<int> v;
    InOrderIterate(root, v);
    Print(v);
    TwoSum(v, target);
    return 0;
}

void InOrderIterate(Node* root, vector<int> &v){
    if(root == NULL) return;
    InOrderIterate(root->left, v);
    v.push_back(root->val);
    InOrderIterate(root->right, v);
}

void Print(vector<int> v){
    for(int i = 0; i < v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

void TwoSum(vector<int> v, int target){
    int start = 0;
    int end = v.size()-1;
    while(start < end){
        if(v[start]+v[end] == target){
            cout<<"Two Sum is : "<<v[start]<<" "<<v[end]<<endl;
            start++;
            end--;
        }
        else if(v[start]+v[end] < target) start++;
        else end--;
    }
    return;
}











