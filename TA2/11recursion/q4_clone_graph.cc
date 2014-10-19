/*
Clone a connected graph
*/
#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;

struct Node{
    int val;
    vector<Node*> neighbor;
    Node(){ }
    Node(int v){
        val = v;
    }
    void SetChildren(Node* n){
        neighbor.push_back(n);
    }
};

Node* Clone(Node* root, unordered_map<Node*, Node*> &mapping);
void Print(Node* root);

int main(){
    Node* root = new Node(0);
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);
    Node* n6 = new Node(6);
    
    root->SetChildren(n1);
    n1->SetChildren(n2);
    n1->SetChildren(n5);
    n1->SetChildren(n6);
    n2->SetChildren(n3);
    n2->SetChildren(n4);
    
    Print(root);
    cout<<"======================="<<endl;
    unordered_map<Node*, Node*> mapping;
    Node* new_root = Clone(root, mapping);
    Print(new_root);
    
    return 0;
}

Node* Clone(Node* root, unordered_map<Node*, Node*> &mapping){
    if(root == NULL){
        return NULL;
    }
    Node* new_node = new Node(root->val);
    mapping[root] = new_node;
    vector<Node*> nei = root->neighbor;
    for(int i = 0; i < nei.size(); ++i){
        Node* child = NULL;
        if(mapping.find(nei[i]) == mapping.end()){
            child = Clone(nei[i], mapping);
        }
        else{
            child = mapping[root];
        }
        new_node->neighbor.push_back(child);
    }
    return new_node;
}

void Print(Node* root){
    if(root == NULL){
        return;
    }
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* cur = q.front();
        q.pop();
        cout<<cur->val<<" ";
        vector<Node*> v = cur->neighbor;
        for(int i = 0; i < v.size(); ++i){
            q.push(v[i]);
        }
    }
    return;
}