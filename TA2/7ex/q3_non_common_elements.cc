/*
3. How to find non- common elements between two string arrays
string a[]={"aaa","bbb","ccc","ddd"}; 
string b[]={"bbb","ccc", “eee”}; 
res should be a,d,e
*/

/*
Need to clarify : 
duplicated in each string array ?
if no : use unordered_set
if yes: use unordered_map
*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

vector<string> FindNonCommon(vector<string> , vector<string> );

int main(){
    string a[] = {"aaa","bbb","ccc","ddd","aaa"}; 
    string b[] = {"bbb","ccc", "eee", "ccc", "eee"};
    int n = sizeof(a)/sizeof(a[0]);
    int m = sizeof(b)/sizeof(b[0]);
    vector<string> v1(a, a+n);
    vector<string> v2(b, b+m);
    vector<string> result = FindNonCommon(v1,v2);
    for(int i = 0; i < result.size(); ++i){
        cout<<result[i]<<" ";
    }
    cout<<endl;
    return 0;
}

vector<string> FindNonCommon(vector<string> v1, vector<string> v2){
    vector<string> result;
    unordered_map<string, string> mapping;
    for(int i = 0; i < v1.size(); ++i){
        mapping[v1[i]] = "a";
    }
    for(int i = 0; i < v2.size(); ++i){
        if(mapping.find(v2[i]) == mapping.end()){
            mapping[v2[i]] = "b";
        }
        else if(mapping[v2[i]] == "b"){
            continue;
        }
        else{
            mapping[v2[i]] = "ab";
        }
    }
    unordered_map<string, string> :: iterator iter;
    for(iter = mapping.begin(); iter != mapping.end(); ++iter){
        string check = iter->second;
        if(check.size() == 1){
            result.push_back(iter->first);
        }
    }
    return result;
}