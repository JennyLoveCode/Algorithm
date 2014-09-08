/*
Q15: (string) Given a string such as “a3b1c4d0” → “aaabcccc” (in place)
intermedia solution ⇒ longer : aaab1ccccd0      aaabcccc
*/
#include <iostream>
#include <locale>
using namespace std;

void replace(string &);

int main(){
    string s("a3b1c4d0e2");
    replace(s);
    cout<<s<<endl;
    return 0;
}

void replace(string &s){
    int len = 0;
    int i = 0;
    int idx = 0;
    //replace alpha whose count < 2 
    //resize string
    while(i < s.size()){
        if(isalpha(s[i])){
            s[idx++] = s[i++];
        }
        int count = 0;
        while(isdigit(s[i])){
            count += count*10 + s[i] -'0';
            s[idx++] = s[i++];
        }
        if(count < 2){
            idx -= 2 - count;
        }
        len += count;
    }
    s.resize(len);

    //replace alpha whose count >= 2
    idx--;
    i = len-1;
    while(idx >= 0){
        if(isdigit(s[idx])){
            int count = 0;
            int weight = 1;
            while(isdigit(s[idx])){
                count += (s[idx] - '0')* weight;
                weight *= 10;
                idx--;
            }
            char c = s[idx];
            //copy alpha
            while(count > 0){
                s[i--] = c;
                count--;
            }
            idx--;
        }
        else{
            s[i--] = s[idx--];
        }
    }
}





