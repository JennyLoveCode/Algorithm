/*
reorder a list according to a pivot k, the nodes less than pivot come before.

5 3 4 1 2  
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

ListNode* Reorder(ListNode* head, int k);
void print(ListNode*);

int main(){
    ListNode* n0 = new ListNode(0);
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(4);
    ListNode* n5 = new ListNode(5);
    
    ListNode* head = n5;
    n5->next = n3;
    n3->next = n4;
    n4->next = n1;
    n1->next = n2;

    int k = 2;
    
    ListNode* res = Reorder(head, k);
    print(res);
    
    return 0;
}

ListNode* Reorder(ListNode* head, int k){
    if(head == NULL || head->next == NULL){
        return head;
    }
    //first part : smaller than k
    ListNode* first_head = NULL;
    ListNode* first = NULL;
    //second part : equal or greater than k
    ListNode* second_head = NULL;
    ListNode* second = NULL;

    ListNode* cur = head;
    while(cur){
        if(cur->val < k){
            if(first == NULL){  
                first_head = cur;
                first = first_head;
            } else{
                first->next = cur;
                first = first->next;
            }
        } else{
            if(second_head == NULL){
                second_head = cur;
                second = second_head;
            }
            else{
                second->next = cur;
                second = second->next;
            }
        }
        cur = cur->next;
    }
    
    if(first_head == NULL){
        return second_head;
    }
    //connect first part and second part
    first->next = second_head;
    //update tail
    if(second != NULL){
        second->next = NULL;
    }
    return first_head;
}

void print(ListNode* head){
    ListNode* cur = head;
    while(cur){
        cout<<cur->val<<" ";
        cur = cur->next;
    }
    cout<<endl;
}