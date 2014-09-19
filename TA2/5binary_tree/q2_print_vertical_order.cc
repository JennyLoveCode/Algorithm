/*
2. print binary tree in vertical order
              0                        ->     3
            / 	\                             1
          1    	   2                          0, 4, 5
        /\    	  /  \                        2
      3	   4      5      6                    6
            \    /
            10 11

*/
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;
    Node(){ }
    Node(int v): val(v), left(NULL), right(NULL){}
};

void PrintVertical(Node* , unordered_map<int, vector<int> > &, int);
void Print(vector<int> &);

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
    
    unordered_map<int, vector<int> > mapping;
    PrintVertical(root,mapping,0);

    unordered_map<int, vector<int> > :: iterator it;
    for(it = mapping.begin(); it != mapping.end(); it++){
        int dist = it->first;
        Print(it->second);
    }
    return 0;
}

void PrintVertical(Node* root, unordered_map<int, vector<int> > &mapping, int dist){
    //base case
    if(root == NULL) return;
    mapping[dist].push_back(root->val);
    PrintVertical(root->left, mapping, dist-1);
    PrintVertical(root->right, mapping, dist+1);
}

void Print(vector<int> &v){
    for(int i = 0; i < v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}