/*
List A and List B, intersection,

A: 1 -> 2 -> 5 -> 6 -> 7 -> 8
            ^
B: 3 -> 4  /

*/

#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int v) : val(v), next(NULL){ }
};

int FindIntersection(ListNode* , ListNode*);

int main(){
    ListNode* n1 =  new ListNode(1);
    ListNode* n2 =  new ListNode(2);
    ListNode* n3 =  new ListNode(3);
    ListNode* n4 =  new ListNode(4);
    ListNode* n5 =  new ListNode(5);
    ListNode* n6 =  new ListNode(6);
    ListNode* n7 =  new ListNode(7);
    ListNode* n8 =  new ListNode(8);

    n1->next = n2;
    n2->next = n5;
    n5->next = n6;
    n6->next = n7;
    n7->next = n8;
    
    n3->next = n4;
    n4->next = n5;

    int intersection = FindIntersection(n1, n3);
    cout<<intersection<<endl;
    return 0;
}

int FindIntersection(ListNode* a, ListNode* b){
    int len_a = 0;
    int len_b = 0;
    //get length of list a
    ListNode* cur = a;
    while(cur != NULL){
        cur = cur->next;
        len_a++;
    }
    //get length of list b
    cur = b;
    while(cur != NULL){
        cur = cur->next;
        len_b++;
    }
    int diff = len_a - len_b;
    //get new starting point for longer list
    ListNode* start_1 = diff > 0 ? a : b;
    ListNode* start_2 = diff > 0 ? b: a;
    while(diff > 0){
        start_1 = start_1->next;
        diff--;
    }
    //track two list to get intersection
    while(start_1 != NULL){
        if(start_1->val == start_2->val){
            return start_1->val;
        }
        start_1 = start_1->next;
        start_2 = start_2->next;
    }
    return INT_MAX;
}