/*
Q7: (LinkedList) Given a single linked list, How to find the middle Node of the 
linked list?
*/
#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int v): val(v), next(NULL){}
};

ListNode* find_middle(ListNode* head){
    if(head == NULL || head->next == NULL) return head;
    ListNode* slow = head;
    ListNode* fast = head->next;
    
    while(fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

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
    
    ListNode* result = find_middle(head);
    cout<<result->val<<endl;
    return 0;
}