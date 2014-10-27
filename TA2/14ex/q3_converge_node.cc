/*
Two lists are converging to a lists, find the converging node.
1->2->3->8->7
		    ^
	        |
     	    5

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

ListNode* CommonNode (ListNode* l1, ListNode* l2);

int main () {
    ListNode* l1 = new ListNode(1);
    ListNode* l2 = new ListNode(5);
    ListNode* n2  = new ListNode(2);
    ListNode* n3  = new ListNode(3);
    ListNode* n8  = new ListNode(8);
    ListNode* n7  = new ListNode(7);
    
    l1->next = n2;
    n2->next = n3;
    n3->next = n8;
    n8->next = n7;
    l2->next = n7;
    
    ListNode* res = CommonNode(l1, l2);
    cout<<res->val<<endl;
    return 0;
}

ListNode* CommonNode (ListNode* l1, ListNode* l2) {
    if (l1 == NULL || l2 == NULL) {
        return NULL;
    }
    //get difference
    ListNode* cur = l1;
    int len1 = 0;
    while (cur) {
        cur = cur->next;
        ++len1;
    }
    cur = l2;
    int len2 = 0;
    while (cur) {
        cur = cur->next;
        ++len2;
    }
    ListNode* cur1 = NULL;
    ListNode* cur2 = NULL;
    
    if (len1 > len2) {
        cur1 = l1;
        cur2 = l2;
    } else {
        cur1 = l2;
        cur2 = l1;
    }
    
    int diff = abs(len1 - len2);
    while (diff > 0) {
        cur1 = cur1->next;
        --diff;
    }
    while (cur1 && cur2 && cur1 != cur2) {
        cur1 = cur1->next;
        cur2 = cur2->next;
    }
    return cur1;
}