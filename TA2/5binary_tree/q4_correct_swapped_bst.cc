/*
4. in BST, two nodes are swapped, find these two and correct them
1   2   6   4   5   3   7
        first       last
    
1   2   4   3   5   6   7
        f   mid
wrong_node.val < prev_node.val
first_wrong_node = prev_node
second_wrong_node = cur_node
*/
#include <iostream>
using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;
    Node(){ }
    Node(int v): val(v),left(NULL),right(NULL){ }
};

void CorrectBST(Node*);
void HelpCorrectBST(Node* , Node* &, Node* &, Node* &, Node* &);
void SwapValue(int* , int*);
void Print(Node*);

int main(){
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* root = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);
    Node* n6 = new Node(6);
    Node* n7 = new Node(7);
    
    root->left = n2;
    root->right = n6;
    n2->left = n1;
    n2->right = n4;
    n6->left = n5;
    n6->right = n7;
    
    Print(root);
    CorrectBST(root);
    cout<<"======================"<<endl;
    Print(root);
    return 0;
}

void CorrectBST(Node* root){
    Node*first = NULL;
    Node* mid = NULL;
    Node* last = NULL;
    Node* prev = NULL; 
    
    HelpCorrectBST(root, first, mid, last, prev);
    if(first && last){
        SwapValue(&(first->val), &(last->val));
    }
    else if(first && mid){
        SwapValue(&(first->val), &(mid->val));        
    }
    return;
}

void HelpCorrectBST(Node* root, Node* &first, Node* &mid, Node* &last, Node* &prev){
    //base case
    if(root == NULL) return;
    //recursive rule
    HelpCorrectBST(root->left, first, mid, last, prev);
    if(prev && prev->val > root->val){
        //try to find first swapped node
        if(!first){
            first = prev;
            mid = root;
        }
        //try to find last swapped node
        else{
            last = root;
        }
    }
    prev = root;
    HelpCorrectBST(root->right, first, mid, last, prev);
}

void SwapValue(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b= tmp;
    return;
}

void Print(Node* root){
    //base case
    if(root == NULL) return;
    //recursive rule
    Print(root->left);
    cout<<root->val<<endl;
    Print(root->right);
}

/*
Reason to pass a pointer by reference
You would want to pass a pointer by reference by if you have a need to modify the pointer 
rather than the object that the pointer is pointing to.
This is similar to why double pointers are used; using a reference to a pointer is 
slightly safer than using pointers.
*/