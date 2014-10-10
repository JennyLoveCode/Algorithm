/*
2. We have a string array, print group anagrams together.
*/
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

void Anagrams(string[], int );

int main(){
    string s[] = {"abc", "bc" , "a", "cb", "bb", "cba", "ab", "ba"};
    int n = sizeof(s)/sizeof(s[0]);
    Anagrams(s, n);
    return 0;
}

void Anagrams(string s[], int n){
    unordered_map<string, vector<string> > mapping;
    for(int i = 0; i < n; ++i){
        string o = s[i];
        sort(s[i].begin(), s[i].end());
        string key = s[i];
        //build mapping
        if(mapping.find(key) == mapping.end()){
            mapping[key] = vector<string>();
        }
        mapping[key].push_back(o);
    }
    //traverse mapping
    unordered_map<string, vector<string> > :: iterator iter;  
    for(iter = mapping.begin(); iter != mapping.end(); ++iter){
        string key = iter->first;
        vector<string> v = mapping[key];
        for(int i = 0; i < v.size(); ++i){
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }
}