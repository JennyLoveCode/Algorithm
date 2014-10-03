/*
6 LCA cannot ensure both two nodes exist in the tree.

6 binary tree two nodes' distance, distance = # of edges between the nodes.

6 binary search tree two nodes' distance

                                    7
                                /          \
                            4               9
                          /    \            /  
                        1       5          8    
                                 \             
                                  6

*/
#include <iostream>
using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int v):val(v),left(NULL),right(NULL){ }
};

Node* A_LCA(Node* , Node* , Node* );
void Find(Node* , int , bool &);
void GetDistance(Node* , Node* , int , int &);

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
    
    Node* p = n6;
    Node* q = n4;
    Node* lca = A_LCA(root, p, q);
    int dist_p = INT_MAX;
    int dist_q = INT_MAX;
    if(lca){
        bool find_t = false;
        int target;
        //LCA is p, check the existence of q, and then get distance from p to q
        if(lca->val == p->val){
            target = q->val;
            Find(root, target, find_t);
            if(find_t){
                cout<<"The LCA for "<<p->val<<" and "<<q->val<<" is "<<lca->val<<endl;
                GetDistance(p, q,0,dist_q);
                cout<<"The distance from "<<p->val<<" and "<<q->val<<" is "<<dist_q<<endl;
            }
        }
        //LCA is q, check the existence of p, and then get distance from q to p
        else if(lca->val == q->val){
            target = p->val;
            Find(root, target, find_t);
            if(find_t){
                cout<<"The LCA for "<<p->val<<" and "<<q->val<<" is "<<lca->val<<endl;
                GetDistance(q, p,0,dist_p);
                cout<<"The distance from "<<q->val<<" and "<<p->val<<" is "<<dist_p<<endl;
            }
        }
        //LCA exists and is not neither q nor q
        else{
            cout<<"The LCA for "<<p->val<<" and "<<q->val<<" is "<<lca->val<<endl;
            GetDistance(lca,p,0,dist_p);
            GetDistance(lca,q,0,dist_q);
            cout<<"The distance from "<<p->val<<" and "<<q->val<<" is "<<dist_p+dist_q<<endl;
        }
    }
    else{
        cout<<"There is no LCA for "<<p->val<<" and "<<q->val<<endl;
    }
    return 0;
}

Node* A_LCA(Node* root, Node* p, Node* q){
    if(root == NULL){
        return NULL;
    }
    if(root->val == p->val || root->val == q->val){
        return root;
    }
    Node* l = A_LCA(root->left, p, q);
    Node* r = A_LCA(root->right, p, q);
    if(l && r){
        return root;
    }
    else{
        return l ? l :r;
    }
}

void Find(Node* root, int target, bool &find_t){
    if(root == NULL){
        return;
    }
    if(root->val == target){
        find_t = true;
        return;
    }
    Find(root->left, target, find_t);
    Find(root->right, target, find_t);
}

void GetDistance(Node* root, Node* p, int cur, int &dist){
    if(root == NULL){
        return;
    }
    if(root->val == p->val){
        dist = cur;
    }
    GetDistance(root->left, p, cur+1, dist);
    GetDistance(root->right, p, cur+1, dist);
}