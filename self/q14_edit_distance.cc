/*
Given two words word1 and word2, find the minimum number of steps required to convert
word1 to word2.
operations: insert, delete, replace
ISLANDER, SLANDER
> 1
MART, KARMA
> 3
KITTEN, SITTING
> 3
INTENTION, EXECUTION
>5
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int Convert (string s1, string s2);

int main () {
    string s1 = "MART";
    string s2 = "KARMA";
    int res = Convert(s1, s2);
    cout<<res<<endl;
    return 0;
}

//state[i][j] indicates the minimum number of operations to convert s1[0, i] to s2[0, j]
int Convert (string s1, string s2) {
    int m = s1.size();
    int n = s2.size();
    vector<vector<int> > state(m+1, vector<int>(n+1, INT_MAX));
    //initialization
    for (int i = 0; i <= m; ++i) {
        state[i][0] = i;
    }
    for (int j = 0; j <= n; ++j) {
        state[0][j] = j;
    }
    //dp
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (s1[i-1] == s2[j-1]) {
                state[i][j] = state[i-1][j-1];
            } else  {
                int insertion = state[i][j-1]+1;
                int deletion = state[i-1][j]+1;
                int replace = state[i-1][j-1]+1;
                state[i][j] = min(min(insertion, deletion), replace);
            }
        }
    }
    return state[m][n];
}