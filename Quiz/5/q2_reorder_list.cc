/*
Q2 Given a linked list, reverse alternate nodes and append at the end  
Example1 Input List:  1  ->  2    ->3->4->5->6
                      curr  next         nnext
Output List:                1->3->5->6->4->2


Example2 Input List:  1->2->3->4->5
                             
Output List:          1->3->5->4->2
*/
#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    
    ListNode () { }
    ~ListNode () { }
    ListNode (int v) : val(v), next(NULL) { }
};

ListNode* ReorderList (ListNode* head);
ListNode* Reorder(ListNode* head);
ListNode* Reverse(ListNode* head);
void print (ListNode* head);

int main () {
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(4);
    ListNode* n5 = new ListNode(5);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    //ListNode* res = Reorder(n1);
    ListNode* res = ReorderList(n1);
    print(res);
    return 0;
}

ListNode* ReorderList (ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    ListNode* cur = head;
    ListNode* next = cur->next;
    ListNode* even_head = NULL;

    while (next) {
        ListNode* nnext = next->next;
        //link even list
        next->next = even_head;
        even_head = next;
        //link odd list
        cur->next = nnext;
        if (nnext == NULL) break;
        cur = nnext;
        next = cur->next;
    }
    //link odd and even list
    cur->next = even_head;

    return head;
}

ListNode* Reorder(ListNode* head){
	if(head == NULL || head->next == NULL){
		return head;
    }
    ListNode* l1= head;
    ListNode* l2 = head->next;
    ListNode* l2_head = l2;
    ListNode* cur = l2->next;

    bool isOdd = true;
    while(cur){
	    if(isOdd){
		    l1->next = cur;
		    l1 = l1->next;
		    isOdd = false;
        } else {
	        l2->next = cur;
	        l2 = l2->next;
	        isOdd = true;
        }	
        cur = cur->next;
    }
    //update tail
    l1->next = NULL;
    l2->next = NULL;
    ListNode* head2 = Reverse(l2_head);
    //connect l1 and reversed l2
    l1->next = head2;
    return head;
}

ListNode* Reverse(ListNode* head){
	if(head == NULL || head->next == NULL){
    		return head;
    }
    ListNode* prev = head;
    ListNode* cur = head->next;
    while(cur){
	    ListNode* next = cur->next;
	    cur->next = prev;
	    prev = cur;
	    cur = next;
    }
    //update tail
    head->next = NULL;
    return prev;
}

void print (ListNode* head) {
    ListNode* cur = head;
    while (cur) {
        cout<<cur->val<<" ";
        cur = cur->next;
    }
    cout<<endl;
}