/*
Given a byte array, which is an encoding of characters. Here is the rule:
a. If the first bit of a byte is 0, that byte stands for a one-byte character
b. If the first bit of a byte is 1, that byte and its following byte together stand 
for a two-byte character
Now implement a function to decide if the last character is a one-byte character or 
a two-byte character
*/
#include <iostream>
#include <vector>
using namespace std;

bool IsOneByte (int arr[], int n);

int main () {
    int arr[] = {0,1,1,1,1,0,0,0};
    int n = sizeof(arr)/sizeof(arr[0]);
    if (IsOneByte(arr, n)) {
        cout<<"T"<<endl;
    } else {
        cout<<"F"<<endl;
    }
    return 0;
}

bool IsOneByte (int arr[], int n) {
    if (arr[n-1] == 1) {
        return false;
    }
    //indicates the last character of string starting at index i 
    //is one-byte or not
    vector<bool> state(n, false);
    state[n-1] = true;
    for (int i = n-2; i >= 0; --i) {
        if (arr[i] == 0 && i+1 < n) {
            state[i] = state[i+1];
        } else if (arr[i] == 1 && i+2 < n) {
            state[i] = state[i+2];
        }
    }
    return state[0];
}