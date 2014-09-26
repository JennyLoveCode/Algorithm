/*
Q19 (Binary tree) K nodes’ lowest common ancestor
*/
#include <iostream>
#include <vector>
using namespace std;

struct node{
    int val;
    node* left;
    node* right;
    
    node(){}
    node(int v): val(v), left(NULL), right(NULL){}
};

node* lca(node*, node*, node* );
node* k_lca(vector<node*> &, node* );

int main(){
    node* root = new node(0);
    node* n1 = new node(1);
    node* n2 = new node(2);
    node* n3 = new node(3);
    node* n4 = new node(4);
    node* n5 = new node(5);
    node* n6 = new node(6);
    node* n7 = new node(7);

    root->left = n1;
    root->right = n2;
    n1->left = n3;
    n1->right = n4;
    n2->left = n5;
    n2->right = n6;
    n3->left = n7;
    
    vector<node*> v;
    v.push_back(n3);
    v.push_back(n4);
    v.push_back(n7);
    
    node* result = k_lca(v, root);
    cout<<result->val<<endl;
    return 0;
}

node* k_lca(vector<node*> &v, node* root){
    if(!root) return NULL;
    
    while(v.size() > 1){
        vector<node*> solu;
        if(v.size() % 2 == 1){
            v.push_back(NULL);
        }
        for(int i = 0; i < v.size(); i += 2){
            node* n = lca(root, v[i],v[i+1]);
            solu.push_back(n);
        }
        v = solu;
    }
    return v[0];
}

//find each node first and then bottom-up: time complexity O(n)
node* lca(node* root, node* a, node* b){
    if(!root) return NULL;
    if(!b) return a;
    if(root == a || root == b) return root;
    node* L = lca(root->left, a, b);
    node* R = lca(root->right, a, b);
    if(L && R) return root;
    return L? L: R;
}