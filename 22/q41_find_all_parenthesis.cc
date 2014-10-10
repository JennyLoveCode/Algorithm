/*
Q41 （）（）（） find all valid permutation using the parenthesis provided.
*/
#include <iostream>
#include <string>
using namespace std;

void Parenthesis(string, int, int ,int );

int main(){
    int n = 3;
    Parenthesis("", n, 0, 0);
    return 0;
}

void Parenthesis(string s, int n, int l, int r){
    //base case
    if(l == n){
        s.append(n-r, ')');
        cout<<s<<endl;
        return;
    }
    //recursive rule
    Parenthesis(s+'(', n, l+1, r);
    if(l > r){
        Parenthesis(s+')', n, l, r+1);
    }
}