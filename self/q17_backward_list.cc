/*
How to print a singly linked list backwards 
*/
#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode () { }
    ~ListNode () { }
    ListNode (int v):val(v), next(NULL) { }
};

void PrintBackward (ListNode* head);

int main () {
    ListNode* head = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(4);
    ListNode* n5 = new ListNode(5);
    
    head->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    PrintBackward(head);
    return 0;
}

void PrintBackward (ListNode* head) {
    if (head == NULL) {
        return;
    }
    PrintBackward(head->next);
    cout<<head->val<<endl;
}