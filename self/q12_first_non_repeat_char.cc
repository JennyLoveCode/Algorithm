/*
Given a string, find its first non-repeating character
*/
#include <iostream>
#include <string>
using namespace std;

struct ListNode{
    int val;
    ListNode* prev;
    ListNode* next;
    
    ListNode () { }
    ~ListNode () { }
    ListNode (int v) : val(v), prev(NULL), next(NULL) {}
};

int main () {

}