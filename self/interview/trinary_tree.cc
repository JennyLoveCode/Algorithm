/*Jian Zhang*/

/*
Question 2: Implement insert and delete in a tri-nary tree. A tri-nary tree is much like a 
binary tree but with three child nodes for each parent instead of two -- with the 
left node being values less than the parent, the right node values greater than 
the parent, and the middle nodes values equal to the parent.
For example, suppose I added the following nodes to the tree in this order: 
5, 4, 9, 5, 7, 2, 2.
The resulting tree would look like this:
  5
/ | \
4 5 9
/ /
2 7
|
2
*/

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* mid;
    TreeNode* right;
    
    TreeNode(){ }
    ~TreeNode(){ }
    TreeNode(int v) : val(v), left(NULL), mid(NULL), right(NULL) { }
};

class TrinaryTree{
private:
    TreeNode* root;
public:
    TrinaryTree() { 
        root = NULL;
    }
    ~TrinaryTree() { }
    TrinaryTree(TreeNode* r) : root(r) { }

    void insert(int );
    //help find position to insert
    TreeNode* find_pos(int);
    TreeNode* find_helper(TreeNode* , int);
    
    TreeNode* remove(int);
    //help find node to remove
    TreeNode* remove_helper(TreeNode* , int);
    TreeNode* MinValueNode(TreeNode* );
    
    void print();
};

void TrinaryTree :: insert(int key){
    TreeNode* new_node = new TreeNode(key);

    TreeNode* pos = find_pos(key);
    if(pos == NULL){
        root = new_node;
        return;
    }
    //insert in mid subtree
    else if(key == pos->val){
        //get to leaf node in the mid subtree
        while(pos->mid != NULL){
            pos = pos->mid;
        }
        pos->mid = new_node;
    }
    //insert in left
    else if(key < pos->val){
        pos->left = new_node;
    }
    //insert in right
    else{
        pos->right = new_node;
    }
}

//find position to insert
TreeNode* TrinaryTree :: find_pos(int target){
    return find_helper(root, target);
}

TreeNode* TrinaryTree :: find_helper(TreeNode* root, int target){
    // Base Cases: root is NULL
    if(root == NULL ) {
        return root;
    }
    // Bases Case: target is present at root
    if(root->val == target){
        return root;
    }
    //Recursive rule: target is smaller than root's value
    if(target < root->val){
        if(root->left == NULL){
            return root;
        }
        return find_helper(root->left, target);
    }
    //Recursive rule: target is larger than root's value
    else{
        if(root->right == NULL){
            return root;
        }
        return find_helper(root->right, target);
    }
}

TreeNode* TrinaryTree :: remove(int target){
    if(root == NULL){
        cout<<"Tree is empty."<<endl;
        return NULL;
    }
    return remove_helper(root, target);
}

TreeNode* TrinaryTree :: remove_helper(TreeNode* root, int target){
    if(root == NULL){
        cout<<"Cannot remove! "<<target<<" does not exist in the tree. "<<endl;
        return root;
    }
    //go to left subtree
    if(target < root->val){
        root->left = remove_helper(root->left, target);
    }
    //go to right subtree
    else if (target > root->val){
        root->right = remove_helper(root->right, target);      
    }
    //find and return node without mid child
    else{
        //has mid child
        if(root->mid != NULL){
            TreeNode* prev = root;
            while(root->mid != NULL) {
                root = root->mid;
            }
            delete root;
            prev->mid = NULL;
            return prev;
        }
        //only have left or right child or no child
        if(root->left == NULL){
            TreeNode* node = root->right;
            delete root;
            return node;
        }
        if(root->right == NULL){
            TreeNode* node = root->left;
            delete root;
            return node;
        }
        //has left and right children
        TreeNode* node = MinValueNode(root->right);
        root->val = node->val;
        //remove leaf node in right subtree
        root->right = remove_helper(root->right, node->val);
    }
    return root;
}

//find minimum value node
TreeNode* TrinaryTree :: MinValueNode(TreeNode* node){
    TreeNode* cur = node;
    //find the left-most leave node
    while(cur->left != NULL){
        cur = cur->left;
    }
    return cur;
}

void TrinaryTree :: print(){
    if(root == NULL){
        cout<<"This is an empty tree. "<<endl;
        return;
    }
    
    cout<<"Print tree by level : left, mid, right"<<endl;
    queue<TreeNode*> q;
    q.push(root);
    int cur_level = 1;
    int next_level = 0;
    while(!q.empty()){
        while(cur_level > 0){
            TreeNode* cur = q.front();
            cout<<cur->val<<" ";
            q.pop();
            cur_level--;
            //push left child to queue
            if(cur->left){
                q.push(cur->left);
                next_level++;
            }
            //push mid child to queue
            if(cur->mid){
                q.push(cur->mid);
                next_level++;
            }
            //push right child to queue
            if(cur->right){
                q.push(cur->right);
                next_level++;
            }
        }
        cout<<endl;
        swap(cur_level, next_level);
    }
}

////////////////////////////////////////////////////////////////////////////////

/*Test Cases*/

////////////////////////////////////////////////////////////////////////////////

void test_insert_one_node(){
    cout<<"test case 1 : insert {5}"<<endl;

    TrinaryTree tri_tree;
    tri_tree.insert(5);
    tri_tree.print();
    cout<<endl;
}

void test_insert_multipe_nodes(){
    cout<<"test case 2 : insert {5,4,9,5,7,2,2}"<<endl;

    TrinaryTree tri_tree;
    int arr[] = {5,4,9,5,7,2,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i = 0; i < n; ++i){
        tri_tree.insert(arr[i]);
    }
    tri_tree.print();
    cout<<endl;
}


void test_remove_one_node(){
    cout<<"test case 3 : delete 5 from {5,4,9,5,7,2,2}"<<endl;

    TrinaryTree tri_tree;
    int arr[] = {5,4,9,5,7,2,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i = 0; i < n; ++i){
        tri_tree.insert(arr[i]);
    }
    tri_tree.remove(5);
    tri_tree.print();
    cout<<endl;
}

void test_remove_multiple_nodes(){
    cout<<"test case 4 : delete 5, 5 from {5,4,9,5,7,2,2}"<<endl;

    TrinaryTree tri_tree;
    int arr[] = {5,4,9,5,7,2,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i = 0; i < n; ++i){
        tri_tree.insert(arr[i]);
    }
    tri_tree.remove(5);
    tri_tree.remove(5);
    tri_tree.print();
    cout<<endl;
}

void test_remove_node_does_not_exist_in_tree(){
    cout<<"test case 5 : delete 100 from {5,4,9,5,7,2,2}"<<endl;

    TrinaryTree tri_tree;
    int arr[] = {5,4,9,5,7,2,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i = 0; i < n; ++i){
        tri_tree.insert(arr[i]);
    }
    tri_tree.remove(100);
    tri_tree.print();
    cout<<endl;
}

void test_remove_from_empty_tree(){
    cout<<"test case 6 : delete 8 from empty tree"<<endl;

    TrinaryTree tri_tree;
    tri_tree.remove(8);
    tri_tree.print();
    cout<<endl;
}

/////////////////////////////////////////////////////////////////////////////////

 /*Main Function*/

//////////////////////////////////////////////////////////////////////////////////

int main(){
    test_insert_one_node();
    test_insert_multipe_nodes();
    test_remove_one_node();
    test_remove_multiple_nodes();
    test_remove_node_does_not_exist_in_tree();
    test_remove_from_empty_tree();
    return 0;
}