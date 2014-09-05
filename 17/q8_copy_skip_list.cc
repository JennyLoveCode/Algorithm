/*
Q8: (LinkedList) How to copy a skip list?
*/
#include <iostream>
#include <unordered_map>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode* forward;
    ListNode(int v): val(v), next(NULL), forward(NULL){}
};

ListNode* copy(ListNode* head){
    unordered_map<ListNode*, ListNode*> mapping;
    for(ListNode* node = head; node != NULL; node = node->next){
        mapping[node] = new ListNode(node->val);
    }
    
    for(ListNode* node = head; node != NULL; node = node->next){
        ListNode* copy_node = mapping[node];
        copy_node->next = mapping[node->next];
        if(node->forward){
            copy_node->forward = mapping[node->forward];
        }
    }
    return mapping[head];
}

void print(ListNode* head){
    ListNode* cur = head;
    while(cur){
        cout<<cur->val<<" ";
        cur = cur->next;
    }
    cout<<endl;
    
    for(ListNode* node = head; node != NULL; node = node->next){
        if(node->forward){
            cout<<node->val<<" "<<node->forward->val<<endl;
        }
    }
}

int main(){
    ListNode* head = new ListNode(0);
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(4);
    ListNode* n5 = new ListNode(5);
    head->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n1->forward = n3;
    n2->forward = n5;
    
    print(head);
    ListNode* result = copy(head);
    cout<<"-------------------------------------------------"<<endl;
    print(result);
    return 0;
}









