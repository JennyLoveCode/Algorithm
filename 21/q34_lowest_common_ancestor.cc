/*
Q34 Lowest Common Ancestor revisited
1. have two pointer pointing to the children
2. K nodes
3. have parent pointer
*/
#include <iostream>
#include <queue>
using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int v):val(v),left(NULL),right(NULL){}
};

//with pointer to parent
struct node{
    int val;
    node* parent;
    node* left;
    node* right;
    node(int v):val(v),parent(NULL),left(NULL),right(NULL){}
};

Node* LCA(Node* , Node* , Node* );
node* lca(node* , node* , node* );
int GetHeight(node* );
Node* KLCA(Node* , queue<Node*> );

int main(){
    Node root(0);
    Node n1(1);
    Node n2(2);
    Node n3(3);
    Node n4(4);
    root.left = &n1;
    root.right = &n2;
    n1.left = &n3;
    n1.right = &n4;
    Node* res = LCA(&root, &n3, &n4);
    cout<<res->val<<endl;
    
    queue<Node*> q;
    q.push(&n4);
    q.push(&n3);
    q.push(&n2);
    Node* common = KLCA(&root, q);
    cout<<"k nodes lca "<<common->val<<endl;
    
    node r(0);
    node n_1(1);
    node n_2(2);
    node n_3(3);
    node n_4(4);
    node n_5(5);
    node n_6(6);
    r.left = &n_1;
    r.right = &n_2;
    n_2.parent = &r;
    n_1.parent = &r;
    n_1.left = &n_3;
    n_1.right = &n_4;
    n_3.parent = &n_1;
    n_4.parent = &n_1;
    node* result= lca(&r, &n_1, &n_4);
    cout<<result->val<<endl;
    return 0;
}

Node* LCA(Node* root, Node* p, Node* q){
    if(root == NULL) return NULL;
    if(root == p || root == q) return root;
    Node* L = LCA(root->left, p, q);
    Node* R = LCA(root->right, p, q);
    if(L && R) return root;
    return L ? L : R;
}

node* lca(node* root, node* p, node* q){
    int hp = GetHeight(p);
    int hq = GetHeight(q);
    int diff = hp - hq;
    if(diff > 0 ){
        //move node q up to make height equal to p
        while(diff > 0){
            q = q->parent;
            diff--;
        }
    }
    else{
        //move node p up to make height equal to q
        while(diff < 0){
            p = p->parent;
            diff++;
        }
    }
    while( p != q){
        p = p->parent;
        q = q->parent;
    }
    return p;
}

int GetHeight(node* root){
    if(root == NULL) return 0;
    int l = GetHeight(root->left);
    int r = GetHeight(root->right);
    return max(l, r) + 1;
}

Node* KLCA(Node* root, queue<Node*> q){
    if(root == NULL) return NULL;
    while(q.size() > 1){
        Node* a = q.front();
        q.pop();
        Node* b = q.front();
        q.pop();
        q.push(LCA(root,a, b));
    }
    return q.front();
}