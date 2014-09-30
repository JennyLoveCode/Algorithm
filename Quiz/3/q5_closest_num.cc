/*
binary search tree, closest number to target(sorted array, closest number to target)
                                     7
                                /          \
                            4               9
                          /    \            /  
                        1       5          8    
                                 \             
                                  6

target = 5,       result = 5.
target = 15,     result = 13
target = 17,     result = 18
target = 8.5,    result = 9
target = 7.5,    result = 7

Naive: InOrder 
target = 11.5
binary search tree search(),
search left → closest number not in right subtree
search right → closest number not in left subtree

closest number must exist in the path we're tracking.

G家
5.1 binary search tree, the smallest number larger than target
5.2 binary search tree, the largest number smaller than target
*/
#include <iostream>
using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int v): val(v),left(NULL),right(NULL){ }
};

int ClosestNum(Node* , int);
int SmallestLarger(Node* , int);

int main(){
    Node* root = new Node(7);
    Node* n4 = new Node(4);
    Node* n9 = new Node(9);  
    Node* n1 = new Node(1);
    Node* n5 = new Node(5);
    Node* n6 = new Node(6);
    Node* n8 = new Node(8);
    root->left = n4;
    root->right = n9;
    n4->left = n1;
    n4->right = n5;
    n5->right = n6;
    n9->left = n8;
    
    int target1 = 10;
    int result = ClosestNum(root, target1);
    cout<<"Closes num to "<<target1<<" is "<<result<<endl;
    
    int target2 = 2;
    int smallest_larger = SmallestLarger(root, target2);
    if(smallest_larger != INT_MIN){
        cout<<"smallest num larger than "<<target2<<" is "<<smallest_larger<<endl;
    }
    else{
        cout<<"There is no num larger than "<<target2<<" in the bst."<<endl;
    }
    return 0;
}

int ClosestNum(Node* root, int target){
    Node* cur = root;
    int result = INT_MAX;
    int diff = INT_MAX;
    //closest value exist in the tracking path of the tree
    while(cur != NULL){
        if(cur->val == target){
            return cur->val;
        }
        else if(target < cur->val){
            if(cur->val - target < diff){
                diff = cur->val-target;
                result = cur->val;
            }
            cur = cur->left;
        }
        else{
            if(target - cur->val < diff){
                diff = target - cur->val;
                result = cur->val;
            }
            cur = cur->right;
        }
    }
    return result;
}

int SmallestLarger(Node* root, int target){
    if(root == NULL){
        return INT_MIN;
    }
    Node* cur = root;
    //INT_MIN indicates there is no node which is larger than target
    int result = INT_MIN;

    while(cur != NULL){
        if(cur->val == target){
            cur = cur->right;
        }
        //update possible smallest num larger than target
        else if(cur->val > target){
            result = cur->val;
            cur = cur->left;
        }
        else{
            cur = cur->right;
        }
    }
    return result;
}