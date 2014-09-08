/*
Q14: (string) Replace all substrings s1 in a string s with s2;
s.size = n    s1.size = m     s2.size = k
case (1) “_” > “20%”
case (2) “20%” > “_”
*/
#include <iostream>
#include <string>
using namespace std;

void replace(string &, const string &, const string &);

int main(){
    string s("IaaaloveaaaGoogle");
    const string s1("aaa");
    const string s2("JENNY");
    replace(s, s1, s2);
    cout<<s<<endl;
    return 0;
}

void replace(string &s, const string &s1, const string &s2){
    if(s1.size() < s2.size()){
        int count = 0;
        for(int i = 0; i < s.size(); i++){
            if(s.compare(i, s1.size(), s1) == 0) 
                count++;
        }
        //iterate from last element to the first element
        int i = s.size()-1;
        int new_size = s.size()+count*(s2.size()-s1.size());
        s.resize(new_size);
        int j = s.size()-1;
        while(i >= s1.size()-1){
            //compare and if there is a match
            if(s.compare(i-s1.size()+1, s1.size(), s1) == 0){
                for(int k = s2.size()-1; k >=0; k--){
                    s[j--] = s2[k];
                }
                i = i-s1.size();
            }
            else{
                s[j--] = s[i--];
            }
        }
        while(i >= 0){
            s[j--] = s[i--];   
        }
    }
    else{
        //iterate from first element to last element
        int i = 0;
        int j = 0;
        while(i < s.size()){
            //compare and if there is a match
            if(s.compare(i, s1.size(), s1) == 0){
                for(int k = 0; k < s2.size(); k++){
                    s[j++] = s2[k];
                }
                i = i+s1.size();
            }
            else{
                s[j++] = s[i++];
            }
        }
        s.resize(j);
    }
}