/*
Given a string S and a string T, count te number of distinct subsequences of T in S
A subsequence of a string is a new string which is formed from  the original string by deleting some
(can be none) of the characters without disturbing the relative positions of the remaining
characters.
e.g. S = "rabbbit" T = "rabbit"
return 3
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int DisctintSub (string t, string s);

int main () {
    string s = "rabbbit";
    string t = "rabbit";
    int res = DisctintSub(t, s);
    cout<<res<<endl;
    return 0;
}

//state[i][j] indicates the number of distinct subsequence of T[0, j-1] in S[0, i-1]
//if s[i-1] == t[j-1] state[i][j] = state[i-1][j] + state[i-1][j-1]
//else state[i][j] = state[i-1][j]
int DisctintSub (string t, string s) {
    int m = t.size();
    int n = s.size();
    vector<int> state(m+1, 0);
    
    state[0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = m; j >= 1; --j) {
            if (s[i-1] == t[j-1]) {
                state[j] += state[j-1];
            }
        }
    }
    return state[m];
}