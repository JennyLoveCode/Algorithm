/*
Q2.5  reverse a linked list using recursion.
*/
#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(){ }
    ListNode(int v):val(v),next(NULL){ }
};

ListNode* Reverse(ListNode* );
ListNode* ReverseIt(ListNode* );
void Print(ListNode* );

int main(){
    ListNode head(0);
    ListNode n1(1);
    ListNode n2(2);
    ListNode n3(3);
    ListNode n4(4);
    head.next = &n1;
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;

    Print(&head);
    //ListNode* new_head = Reverse(&head);
    ListNode* new_head = ReverseIt(&head);
    Print(new_head);
    return 0;
}

ListNode* Reverse(ListNode* head){
    //base case
    if(head == NULL || head->next == NULL){
        return head;
    }
    //recursive rule
    ListNode* new_head = Reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return new_head;
}

ListNode* ReverseIt(ListNode* head){
    if(head == NULL || head->next == NULL) return head;
    ListNode* prev = head;
    ListNode* cur = head->next;
    ListNode* next = cur->next;
    while(cur){
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    head->next = NULL; //update tail
    return prev;
}

void Print(ListNode* head){
    ListNode* cur = head;
    while(cur){
        cout<<cur->val<<" ";
        cur = cur->next;
    }
    cout<<endl;
}

/*
utilize recursion: stack store node in reversed order
*/