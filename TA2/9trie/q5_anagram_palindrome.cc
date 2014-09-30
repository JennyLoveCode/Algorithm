/*
5. We have a string, how we determine whether the string can be represented as palindrome. 

edited   -> false
edied	-> edide->   true
assume they are all characters.

*/
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

bool IsPalindrome(string );

int main(){
    string s = "ediedc";
    bool result = IsPalindrome(s);
    if(result){
        cout<<"True"<<endl;
    }
    else{
        cout<<"False"<<endl;
    }
    return 0;
}

bool IsPalindrome(string s){
    //prepare hashmap
    unordered_map<char,int> mapping;
    for(int i = 0; i < s.size(); ++i){
        mapping[s[i]]++;
    }
    
    //check
    int odd_count = 0;
    unordered_map<char,int> :: iterator iter;
    for(iter = mapping.begin(); iter != mapping.end(); ++iter){
        if(iter->second % 2 == 1){
            odd_count++;
        }
    }
    if(s.size() % 2 == 1){
        return odd_count == 1;
    }
    else{
        return odd_count == 0;
    }
}