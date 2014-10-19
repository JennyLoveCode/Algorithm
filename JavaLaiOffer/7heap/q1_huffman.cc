/*
Huffman encoding
    
        Huffman Tree
         FDCABE 100
F 45                 DCABE 55
                DC 25          ABE 30
            D 12    C 13     AB 14    E 16
                            A5    B9
*/
#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;

struct TreeNode{
    string str;
    int freq;
    string code;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(){ }
    TreeNode(string s, int f){
        str = s;
        freq = f;
        code = "";
        left = NULL;
        right = NULL;
    }
};

//comparator for min heap
struct Comparator{
    bool operator() (const TreeNode* n1, const TreeNode* n2) const{
        return n1->freq > n2->freq;
    }
};

TreeNode* BuildTree(string str[], int freq[], int n);
void SetHuffCode(TreeNode* root, string s);
void PrintHuffTree(TreeNode* root);

int main(){
    string str[] = {"A","B","C","D","E","F"};
    int freq[] = {5,9,13,12,16,45};
    int n = sizeof(freq)/sizeof(freq[0]);

    TreeNode* root = BuildTree(str, freq, n);
    SetHuffCode(root,"");
    PrintHuffTree(root);
    //cout<<root->str<<" "<<root->freq<<" "<<root->code<<endl;
    return 0;
}

TreeNode* BuildTree(string str[], int freq[], int n){
    //build heap first
    vector<TreeNode*> v;
    for(int i = 0; i < n; ++i){
        TreeNode* cur = new TreeNode(str[i],freq[i]);
        v.push_back(cur);
    }
    priority_queue<TreeNode*, vector<TreeNode*>, Comparator> heap(v.begin(),v.end());
    
    //build Huffman tree
    TreeNode* l = NULL;
    TreeNode* r = NULL;
    while(heap.size() > 1){
        //fetch two minimum node 
        l = heap.top();
        heap.pop();
        r = heap.top();
        heap.pop();
        //create new internal node
        TreeNode* new_node = new TreeNode(l->str+r->str, l->freq+r->freq);
        new_node->left = l;
        new_node->right = r;
        heap.push(new_node);
    }
    //last node in the heap is the root of Huffman tree
    TreeNode* root = heap.top();
    heap.pop();
    root->left = l;
    root->right = r;
    return root;
}

void SetHuffCode(TreeNode* root, string s){
    if(root == NULL){
        return;
    }
    //assign Huffman code
    root->code = s;
    SetHuffCode(root->left, s+"0");
    SetHuffCode(root->right, s+"1");
}

void PrintHuffTree(TreeNode* root){
    if(root == NULL){
        return;
    }
    PrintHuffTree(root->left);
    cout<<root->str<<" "<<root->freq<<" Huff "<<root->code<<endl;
    PrintHuffTree(root->right);   
}