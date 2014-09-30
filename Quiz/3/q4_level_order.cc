/*
4 level order traversal of binary tree
                                     7
                                /          \
                            4               9
                          /    \            /  
                        1       5        8    
                                /              
                              3    

List<List<Node>> result. 

result.get(0) → [7]
result.get(1) → [4, 9]
result.get(2) → [1, 5, 8]
result.get(3) → [3]

NO BFS.

DFS to make every node has depth attribute
left right root
*/
#include <iostream>
#include <vector>
using namespace std;

struct Node{
    int val;
    int depth;
    Node* left;
    Node* right;
    Node(int v): val(v),depth(-1),left(NULL),right(NULL){ }
};

void LevelTraverse(Node* );
void LevelHelp(Node* ,vector<vector<int> > & );
void GetDepth(Node* , int );
void Print(vector<vector<int> > );
void LevelK(Node* , int );
void LevelKHelp(Node* , int , int );

int main(){
    Node* root = new Node(7);
    Node* n4 = new Node(4);
    Node* n9 = new Node(9);  
    Node* n1 = new Node(1);
    Node* n5 = new Node(5);
    Node* n3 = new Node(3);
    Node* n8 = new Node(8);
    root->left = n4;
    root->right = n9;
    n4->left = n1;
    n4->right = n5;
    n5->left = n3;
    n9->left = n8;
    
    //LevelTraverse(root);
    LevelK(root, 2);
    return 0;

}

void LevelTraverse(Node* root){
    GetDepth(root, 0);
    vector<vector<int> > result;
    LevelHelp(root, result);
    Print(result);
}

void LevelHelp(Node* root,vector<vector<int> > &result){
    if(root == NULL){
        return;
    }
    if(result.size() <= root->depth){
        result.push_back(vector<int>() );
    }
    LevelHelp(root->left, result);
    LevelHelp(root->right, result);
    int d = root->depth;
    result[d].push_back(root->val);
    cout<<"d is "<<d<<" val is "<<root->val<<endl;
}

void GetDepth(Node* root, int d){
    if(root == NULL){
        return;
    }
    root->depth = d;
    cout<<"node "<<root->val<<" depth is "<<root->depth<<endl;
    GetDepth(root->left, d+1);
    GetDepth(root->right, d+1);
}

void Print(vector<vector<int> > v){
    for(int i = 0; i < v.size(); ++i){
        for(int j = 0; j < v[i].size(); ++j){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
}

/*
traversal kth layer of binary tree
*/
void LevelK(Node* root, int k){
    LevelKHelp(root, k, 0);
}

void LevelKHelp(Node* root, int k, int cur){
    //base case
    if(root == NULL){
        return;
    }
    if(cur == k){
        cout<<root->val<<endl;
        return;
    }
    LevelKHelp(root->left, k, cur+1);
    LevelKHelp(root->right, k, cur+1);
}