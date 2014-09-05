/*
Q9: (Graph) How to copy a graph with possible cycles? G>G’
*/
#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

struct Node{
    int val;
    vector<Node*> neighbor;
    Node(int v): val(v){}
};

Node* deep_copy(Node* n, unordered_map<Node*, Node*> &mapping){
    if(mapping.find(n) != mapping.end()){
        return mapping[n];
    }
    
    Node* node = new Node(n->val);
    mapping[n] = node;
    for(int i = 0; i < n->neighbor.size(); i++){
        node->neighbor.push_back(deep_copy(n->neighbor[i], mapping));
    }
    return node;
}

Node* copy_graph(Node* n){
    unordered_map<Node*, Node*> mapping;
    return deep_copy(n, mapping);
}

void print(Node* n){
    unordered_set<Node*> visited;
    queue<Node*> q;
    q.push(n);
    
    while(!q.empty()){
        Node* cur = q.front();
        cout<<cur->val<<" ";
        q.pop();
        if(visited.find(cur) == visited.end()){
            visited.insert(cur);
            for(int i = 0; i < cur->neighbor.size(); i++){
                q.push(cur->neighbor[i]);
            }
        }
    }
    cout<<endl;
}

int main(){
/*
           1---2---4
            \  /
             \3----5
*/
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);
    n1->neighbor.push_back(n2);
    n1->neighbor.push_back(n3);
    n2->neighbor.push_back(n1);
    n2->neighbor.push_back(n4);
    n3->neighbor.push_back(n1);
    n3->neighbor.push_back(n5);
    n4->neighbor.push_back(n2);
    n5->neighbor.push_back(n3);
    
    print(n1);
    Node* result = copy_graph(n1);
    cout<<"----------------------------"<<endl;
    print(result);
    return 0;
}
/*
Method: build a hash_map to avoid duplication when copying a node.
        recursion
*/