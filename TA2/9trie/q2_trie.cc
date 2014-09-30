/*
2. write a trie class, including insert, search. 
*/
#include <iostream>
#include <vector>
using namespace std;

struct Node{
    char val;
    vector<Node*> neighbor;
    Node(char ch): val(ch){ }
};

class Trie{
private:
    Node* root;
    
public:
    Trie(Node* r){
        root = r;
    }
    void Insert(string s);
    bool Find(string s);
};

void Trie :: Insert(string s){
    Node* cur = root;
    for(int i = 0; i < s.size(); ++i){
        //indicate whether find char in trie
        bool exist = false;
        for(int j = 0; j < cur->neighbor.size(); ++j){
            if((cur->neighbor[j])->val == s[i]){
                exist = true;
                cur = cur->neighbor[j];
                break;
            }
        }
        if(!exist){
            Node* new_node = new Node(s[i]);
            (cur->neighbor).push_back(new_node);
            cur = new_node;
        }
    }
}

bool Trie :: Find(string s){
    Node* cur = root;
    for(int i = 0; i < s.size(); ++i){
        vector<Node*> v = cur->neighbor;
        bool exist = false;
        for(int j = 0; j < v.size(); ++j){
            if(s[i] == v[j]->val){
                cur = v[j];
                exist = true;
                break;
            }
        }
        if(!exist){
            return false;
        }
    }
    return true;
}

int main(){
    Node* root = new Node('r');
    Trie t(root);
    t.Insert("happy");
    bool result = t.Find("sad");
    if(result){
        cout<<"Find happy !"<<endl;
    }
    else{
        cout<<"Cannot find"<<endl;
    }
    return 0;
}