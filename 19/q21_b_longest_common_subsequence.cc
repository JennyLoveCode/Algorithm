/*
Q21b. (DP) Given two strings S1 and S2, how to find their longest common subsequence 
(not necessarily contiguous)?
A == student
i
B == swedenasyt
j
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int LongestCommonSubsequence(string , string );

int main(){
    string s1 = "student";
    string s2 = "swedenasyt";
    int result = LongestCommonSubsequence(s1,s2);
    cout<<result<<endl;
    return 0;
}

int LongestCommonSubsequence(string s1, string s2){
    vector<vector<int> > mat(s1.size()+1, vector<int>(s2.size()+1, 0));
    
    for(int i = 1; i <= s1.size(); ++i){
        for(int j = 1; j <= s2.size(); ++j){
            int max_len = 0;
            int cur_len = 0;
            for(int k = 1; k<= j; ++k){
                if(s1[i-1] == s2[k-1]){
                    cur_len = mat[i-1][k-1] + 1;
                }
                else{
                    cur_len = mat[i-1][k-1];
                }
                max_len = max(cur_len, max_len);
            }
            mat[i][j] = max_len;
        }
    }
    
    return mat[s1.size()][s2.size()];
}

/*
m[i][j] indicates maximum number of common subsequence ending at ith of string 1
and jth of string 2
*/