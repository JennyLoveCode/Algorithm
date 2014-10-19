/*
Print out all phone combinations phone number.
*/
#include <iostream>
#include <string>
using namespace std;

void PhoneNum(string num[], string s, string phonenum, int idx);

int main(){
    string num[] = {"", "", "abc", "def", "def","jkl", "mno", "pqrs", "tuv", "wxyz"};
    string s = "23";
    PhoneNum(num, s, "", 0);
    return 0;
}

void PhoneNum(string num[], string s, string phonenum, int idx){
    if(idx == s.size()){
        cout<<phonenum<<endl;
        return;
    }

    string cur = num[s[idx]-'0'];
    for(int i = 0; i < cur.size(); ++i){
        PhoneNum(num, s, phonenum+cur[i], idx+1);
    }
}