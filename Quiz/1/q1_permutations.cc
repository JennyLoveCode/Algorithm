/*
Q: Let assume we a string  aaaabcz,  how to print out all its permutations given that 
it has duplicated letters.
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void Permutation(string &, int);
void Swap(string &, int, int);

int main(){
    string str = "abbc";
    Permutation(str, 0);
    return 0;
}

void Permutation(string &str, int idx){
    //base case: swapped index arrives the ending point
    if(idx == str.size()){
        cout<<str<<endl;
        return;
    }
    //DFS
    vector<bool> duplicated(26, false);
    for(int i = idx; i < str.size(); i++){
        if(duplicated[str[i]-'a'] == false){
            duplicated[str[i]-'a'] = true;
            Swap(str, idx, i);
            Permutation(str, idx+1);
            Swap(str, idx, i);
        }
    }
}

void Swap(string &str, int idx,  int i){
    char c = str[idx];
    str[idx] = str[i];
    str[i] = c;
}