/*
Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2
for example, s1 = "aabcc", s2 = "dbbca"
s3 = "aadbbcbcac" true
s3 = "aadbbbaccc" false
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool Interleave (string s1, string s2, string s);

int main () {
    string s1 = "aabcc";
    string s2 = "dbbca";
    //string s = "aadbbcbcac";
    string s = "aadbbbaccc";
    
    bool res = Interleave(s1, s2, s);
    if (res) {
        cout<<"T"<<endl;
    } else {
        cout<<"F"<<endl;
    }
    return 0;
}

//state[i][j] whether first i characters of s1
//and first j characters of s2 can compose
//first i+j characters of s
bool Interleave (string s1, string s2, string s) {
    int m = s1.size();
    int n = s2.size();
    if ( m+n != s.size()) {
        return false;
    }
    vector<vector<bool> > state(m+1, vector<bool>(n+1, false));
    //initialize
    state[0][0] = true;
    for (int i = 1; i <= m; ++i) {
        state[i][0] = state[i-1][0] && s1[i-1] == s[i-1];
    }
    for (int j = 1; j <= n; ++j) {
        state[0][j] = state[0][j-1] && s2[j-1] == s[j-1];
    }
    //dp
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <=n; ++j) {
            bool check1 = state[i-1][j] && s1[i-1] == s[i+j-1];
            bool check2 = state[i][j-1] && s2[j-1] == s[i+j-1];
            state[i][j] = check1 || check2;
        }
    }
    return state[m][n];
}   