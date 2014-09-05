/*
Q7(b): Using merge sort to sort a linked list
*/
#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int v):val(v), next(NULL){}
};

void split(ListNode* head, ListNode** a_ref, ListNode** b_ref){
    //only one node
    if(head == NULL || head->next == NULL){
        *a_ref = head;
        *b_ref = NULL;
    }
    else{
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;
        }
        *a_ref = head;
        *b_ref = slow->next;
        slow->next = NULL;
    }
}

ListNode* sorted_merge(ListNode* a, ListNode* b){
    ListNode dummy(-1);
    ListNode* cur = &dummy;
    while(a && b){
        if(a->val <= b->val){
            cur->next = a;
            a = a->next;
        }
        else{
            cur->next = b;
            b = b->next;
        }
        cur = cur->next;    
    }
    if(a) cur->next = a;
    if(b) cur->next = b;
    return dummy.next;
}

void merge_sort(ListNode** head_ref){
    //base case
    ListNode* head = *head_ref;
    if(head == NULL || head->next == NULL) return;
    //recursive rule
    ListNode* a = NULL;
    ListNode* b = NULL;
    split(head, &a, &b);
    merge_sort(&a);
    merge_sort(&b);
    *head_ref = sorted_merge(a, b);
}

void print(ListNode* head){
    while(head){
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<endl;
}

int main(){
    ListNode* head = new ListNode(9);
    ListNode* cur = head;
    for(int i = 8; i > 0; i--){
        cur->next = new ListNode(i);
        cur = cur->next;
    }
    print(head);
    merge_sort(&head);
    print(head);
    return 0;
}

/*
MergeSort(headRef)
1) If head is NULL or there is only one element in the Linked List 
    then return.
2) Else divide the linked list into two halves.  
      FrontBackSplit(head, &a, &b);  a and b are two halves
3) Sort the two halves a and b.
      MergeSort(a);
      MergeSort(b);
4) Merge the sorted a and b (using SortedMerge() discussed here) 
   and update the head pointer using headRef.
     *headRef = SortedMerge(a, b);
*/

/*
modify pointer inside the function:

1. reference to pointer: void func(int*& rpInt);

2. pointer to pointer: void func(int** ppInt);
*/