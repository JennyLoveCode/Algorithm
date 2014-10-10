/*
5. Find a pair equal to the given sum in a Balanced BST, return boolean if exists.
*/
#include <iostream>
#include <stack>
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
void TwoSumBST(Node* , int );

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
    //InOrderIterate(root, v);
    //Print(v);
    //TwoSum(v, target);
    TwoSumBST(root, target);
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

//space complexity : O(n)
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

//two sum : O(logn)
void TwoSumBST(Node* root, int target){
    if(root == NULL) return;
    stack<Node*> s1;
    stack<Node*> s2;
    bool done1 = false; //indicate traverse from left most
    bool done2 = false; //indicate traverse from right most
    Node* cur1 = root;
    Node* cur2 = root;
    int val1, val2;
    
    while(true){
        cout<<"while loop outer"<<endl;
        //track small value
        while(done1 == false){
            cout<<"s1 "<<endl;
            if(cur1 != NULL){
                s1.push(cur1);
                cout<<"s1 push "<<cur1->val<<endl;
                cur1 = cur1->left;
            }
            else{
                if(!s1.empty()){
                    val1 = s1.top()->val;
                    s1.pop();
                    cout<<"s1 pop "<<val1<<endl;
                    cur1 = cur1->right;
                }
                done1 = true;
            }
        }
        
        cout<<"jump 1"<<endl;
        //track large value
        while(done2 == false){
            cout<<"s2"<<endl;
            if(cur2 != NULL){
                s2.push(cur2);
                cout<<"s2 push "<<cur2->val<<endl;
                cur2 = cur2->right;
            }
            else{
                if(!s2.empty()){
                    val2 = s2.top()->val;
                    s2.pop();
                    cur2 = cur2->left;
                }
                done2 = true;
            }
        }
        
        cout<<"val1 "<<val1<<" val2 "<<val2<<endl;
        if(val1 >= val2){
            cout<<"BST ==> cannot find"<<endl;
            return;
        }
        else if(val1 + val2 == target){
            cout<<"BST ==> Two sum for "<<target<<" is "<<val1<<" and "<<val2<<endl;
            done1 = false;
        }
        else if(val1 +val2 > target){
            done2 = false;
        }
        else if(val1 + val2 < target){
            done1 = false;
        }
    }
    return;
}