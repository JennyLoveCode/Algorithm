/*
6. find Nth node from the end of a Linked List
*/
#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(){ }
    ListNode(int v): val(v), next(NULL){ } 
};

ListNode* FindNth(ListNode* , int );

int main(){
    ListNode* head = new ListNode(0);
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(4);
    ListNode* n5 = new ListNode(5);
    ListNode* n6 = new ListNode(6);
    head->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    int n = 5;
    ListNode* result = FindNth(head, n);
    cout<<result->val<<endl;
    return 0;
}

ListNode* FindNth(ListNode* head, int n){
    if(head == NULL) return NULL;
    ListNode* fast = head;
    ListNode* slow = head;
    for(int i = 0; i < n; i++){
        fast = fast->next;
        if(fast == NULL){
            return NULL;
        }
    }
    while(fast){
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}