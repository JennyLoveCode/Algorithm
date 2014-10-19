/*
Copy a skip list.
*/

#include <iostream>
#include <unordered_map>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode* random;
    
    ListNode() { }
    ~ListNode() { }
    ListNode(int v) : val(v), next(NULL), random(NULL){ }
};

ListNode* Copy(ListNode* head);
ListNode* CopyHelper(ListNode* head, unordered_map<ListNode*, ListNode*> &mapping);
void print(ListNode* head);
ListNode* CopyIt (ListNode* head);

int main(){
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(4);
    ListNode* n5 = new ListNode(5);

    ListNode* head = n5;
    n5->next = n3;
    n5->random = n1;

    n3->next = n1;
    n3->random = n2;    

    n1->next = n2;
    n1->random = n4;
    
    n2->next = n4;
    
    //ListNode* res = Copy(head);
    ListNode* res = CopyIt(head);
    print(res);
    return 0;
}

ListNode* CopyIt (ListNode* head) {
    ListNode* cur = head;
    unordered_map<ListNode*, ListNode*> mapping;
    
    ListNode* new_head = NULL;
    ListNode* new_cur = NULL;
    
    while(cur){
        ListNode* next = NULL;
        ListNode* random = NULL;
        if (mapping.find(cur) == mapping.end()) {
            new_cur = new ListNode(cur->val);
            mapping[cur] = new_cur;
        } else {
            new_cur = mapping[cur];
        }
        if (new_head == NULL) {
            new_head = new_cur;
        }
        if (cur->next) {
           if (mapping.find(cur->next) == mapping.end()) {
                next = new ListNode(cur->next->val);
                mapping[cur->next] = next;
            } else {
                next = mapping[cur->next];
            }
            new_cur->next = next;
        }
        if (cur->random) {
           if (mapping.find(cur->random) == mapping.end()) {
                random = new ListNode(cur->random->val);
                mapping[cur->random] = random;
            } else {
                random = mapping[cur->random];
            }
            new_cur->random = random;
        }
        cur = cur->next;
    }
    return new_head;
}

ListNode* Copy(ListNode* head){
    unordered_map<ListNode*, ListNode*> mapping;
    return CopyHelper(head, mapping);
}

ListNode* CopyHelper(ListNode* head, unordered_map<ListNode*, ListNode*> &mapping){
    //base case
    if(head == NULL){
        return NULL;
    }
    if(mapping.find(head) != mapping.end()){
        return mapping[head];
    }
    //create copied node and update info in mapping
    ListNode* new_node = new ListNode(head->val);
    mapping[head] = new_node; 
    //recursive rule
    new_node->next = CopyHelper(head->next, mapping);
    new_node->random = CopyHelper(head->random, mapping);
    return new_node;
}

void print(ListNode* head){
    ListNode* cur = head;
    while(cur){
        cout<<cur->val<<" ";
        if(cur->next){
            cout<<(cur->next)->val<<" ";
        }
        if(cur->random){
            cout<<(cur->random)->val<<" ";
        }
        cout<<endl;
        cur = cur->next;
    }
}