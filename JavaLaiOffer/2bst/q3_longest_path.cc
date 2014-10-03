/*
3. Binary Tree, diameter, from one node to another, longest path.
length of path = # of nodes on the path.

                             5
                         /        \  
                    1              9 
                       \          /    \
                         3      8     11

*/
#include <iostream>
using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int v):val(v),left(NULL),right(NULL){}
};

int LongestPath(Node* );
int MaxHeight(Node* );

int main(){
    Node* n5 = new Node(5);
    Node* n1 = new Node(1);
    Node* n9 = new Node(9);
    Node* n3 = new Node(3);
    Node* n8 = new Node(8);
    Node* n11 = new Node(11);
    
    n5->left = n1;
    n5->right = n9;
    n1->right = n3;
    n9->left = n8;
    n9->right = n11;
    
    int result = LongestPath(n5);
    cout<<result<<endl;
    return 0;
}

int LongestPath(Node* root){
    int left_path = MaxHeight(root->left);
    int right_path = MaxHeight(root->right);
    return left_path + right_path;
}

int MaxHeight(Node* root){
    if(root == NULL){
        return 0;
    }
    int l = MaxHeight(root->left);
    int r = MaxHeight(root->right);
    return max(l,r)+1;
}