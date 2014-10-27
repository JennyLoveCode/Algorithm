/*
Use recursion to reverse a string.
*/
#include <iostream>
#include <string>
using namespace std;

string Reverse(string s);
void ReverseHelp(string &s, int begin, int end);

int main(){
    string s = "abcdefg";
    string res = Reverse(s);
    cout<<res<<endl;
    return 0;
}

string Reverse(string s){
    ReverseHelp(s, 0, s.size()-1);
    return s;
}

void ReverseHelp(string &s, int begin, int end){
    if(begin < end){
        swap(s[begin], s[end]);
        ReverseHelp(s, ++begin, --end);
    }
    return;
}