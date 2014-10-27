/*
Find the first non-repeated character of a string.
e.g. 	“abccdeda”  b
*/
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

char FindFirst (string s);

int main () {
    string s = "abccdedba";
    char res = FindFirst(s);
    cout<<res<<endl;
    return 0;
}

char FindFirst (string str) {
    int n = str.size();
    unordered_map<char, int> mapping;
    char res;

    for (int i = 0; i < n; ++i) {
        if (mapping.find(str[i]) == mapping.end()) {
            mapping[str[i]] = i;
        } else {
            mapping[str[i]] = -1;
        }
    }
    
    unordered_map<char, int> :: iterator iter;
    int idx = INT_MAX;
    for (iter = mapping.begin(); iter != mapping.end(); ++iter) {
        if (iter->second != -1) {
            idx = min(idx, iter->second);
        }
    }
    return str[idx];
}