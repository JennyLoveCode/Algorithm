/*
Given a String, we can insert characters at any places, what is the least number of 
insertions we can do to make it a palindrome?

“abca” → “abcba”   insert 1
“abcdc” → “abcdcba” insert 2
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int MinInsertion (string s);

int main () {
    string s = "abca";
    int res = MinInsertion(s);
    cout<<res<<endl;
    return 0;
}

int MinInsertion (string s) {
    int n = s.size();
    vector<vector<int> > state(n, vector<int>(n,0));
    //initialization
    state[0][0] = 0;
    for (int i = 1; i < n; ++i) {
        state[i][i] = 0;
        if (s[i-1] == s[i]) {
            state[i-1][i] = 0;
        } else {
            state[i-1][i] = 1;
        }
    }
    //dp
    for (int k = 2; k < n; ++k) {
        for (int i = 0; i+k < n; ++i) {
            int j = i+k;
            if (s[i] == s[j]) {
                state[i][j] = state[i+1][j-1];
            } else {
                state[i][j] = 1 + min(state[i+1][j], state[i][j-1]);
            }
        }
    }
    return state[0][n-1];
}