/*
1 1
2 11
3 21
4 1211
5 111221
6 312211
7 13112221
8 1113213211
*/
#include <iostream>
#include <string>
using namespace std;

string CountAndSay(string , int );

int main(){
    string first = "1";
    int n = 8;
    string result = CountAndSay(first, n);
    cout<<result<<endl;
    return 0;
}

string CountAndSay(string first, int n){
    string s = first;
    for(int cur = 1; cur < n; ++cur){
        int len = s.size();
        string tmp;
        int count = 1;
        for(int i = 1; i < len; i++){
            //continuous same chars 
            if(s[i] == s[i-1]){
                count++;
                //arrive the end of string
                if(i == len-1){
                    tmp += to_string(count);
                    tmp += s[i-1];
                    break;
                }
            }
            //meet distinct char 
            else{
                tmp += to_string(count)+s[i-1];
                count = 1;
            }
        }
        //update if last character is distinct
        if(count == 1){
            tmp += "1";
            tmp += s[len-1];
        }
        s = tmp;
    }
    return s;
}