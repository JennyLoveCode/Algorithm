/*
Q17: Swap each pair of nodes in the linked list
*/
#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    
    ListNode(){}
    ListNode(int v): val(v), next(NULL){}
};

ListNode* swap(ListNode* );
void print(ListNode* );

ListNode* swap(ListNode* head){
    if(head == NULL || head->next == NULL) return head;
    ListNode dummy(-1);
    dummy.next = head;
    
    ListNode* prev = &dummy;
    ListNode* cur = head;
    ListNode* next = head->next;
    while(next){
        prev->next = next;
        cur->next = next->next;
        next->next = cur;
        
        prev = cur;
        cur = prev->next;
        next = cur == NULL ? NULL:cur->next;
    }
    return dummy.next;
}

void print(ListNode* head){
    ListNode* cur = head;
    while(cur){
        cout<<cur->val<<" ";
        cur = cur->next;
    }
    cout<<endl;
}

int main(){
    ListNode* head = new ListNode(1);
    ListNode* n1 = new ListNode(2);
    ListNode* n2 = new ListNode(3);
    ListNode* n3 = new ListNode(4);
    ListNode* n4 = new ListNode(5);
    ListNode* n5 = new ListNode(6);
    
    head->next = n1;
    n1->next = n2;
    n2->next =n3;
    n3->next =n4;
    //n4->next =n5;
    print(head);
    
    ListNode* result = swap(head);
    print(result);
    return 0;
}










