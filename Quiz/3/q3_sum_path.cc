/*
3 sum of all paths from root to leaf nodes in a binary tree.

                                    7
                                /          \
                            4               9
                          /    \            /  
                        1       5        8    
                                /              
                              3      
sum = 741 + 7453 + 798 = 8992
*/
#include <iostream>
using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int v):val(v),left(NULL),right(NULL) {}
};

void SumPath(Node* , int, int &);

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
    
    int sum = 0;
    SumPath(root,0, sum);
    cout<<"Sum is "<<sum<<endl;
    return 0;
}

void SumPath(Node* root, int prev, int &sum){
    cout<<"prev "<<prev<<endl;
    //base case: arrive leaf node
    if(root->left == NULL && root->right == NULL){
        sum += prev*10 + root->val;
        return;
    }
    prev = prev*10+root->val;
    if(root->left){
        SumPath(root->left, prev, sum);
    }
    if(root->right){
        SumPath(root->right,prev,sum);
    }
}

/*
DFS 
global sum
do not have to save path
*/