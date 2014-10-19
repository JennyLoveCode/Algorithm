/*
even- odd reorder, given a list.
	0->1->2->3->4
	0->2->4…->1->3….
*/
#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    
    ListNode() { }
    ~ListNode() { }
    ListNode(int v) : val(v), next(NULL) { }
};

ListNode* Reorder(ListNode* head);
void print(ListNode* head);

int main() {
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
    //n4->next = n5;

    ListNode* res = Reorder(head);
    print(res);
    return 0;
}

ListNode* Reorder(ListNode* head){
    //0 or 1 node in the list
    if(head == NULL || head->next == NULL){
        return head;
    }
    //even linked list
    ListNode* l1 = head;
    //odd linked ist
    ListNode* head2 = head->next;
    ListNode* l2 = head2;
    //traverse nodes in linked list
    ListNode* cur = l2->next;
    bool even = true;
    
    while(cur){
        if(even){
            l1->next = cur;
            l1 = l1->next;
        }
        else{
            l2->next = cur;
            l2 = l2->next;
        }
        even = !even;
        cur = cur->next;
    }
    
    //connect even and odd list
    l1->next = head2;
    //update tail
    l2->next = NULL;
    
    return head;
}

void print(ListNode* head){
    ListNode* cur = head;
    while(cur){
        cout<<cur->val<<" ";
        cur = cur->next;
    }
    cout<<endl;
}