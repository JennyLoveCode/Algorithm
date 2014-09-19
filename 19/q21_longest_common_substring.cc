/*
Q21. (DP) Given two strings S1 and S2, how to find their longest common substring?
Example, student & sweden, then return “den”.
      012345
A[] = sweden;
        i == 3
      0123456
B[] = student;
        j == 3
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

string longest_common_substr(string &, string &);

int main(){
    string s1 = "sweden";
    string s2 = "student";
    cout<<longest_common_substr(s1,s2)<<endl;
    return 0;
}

string longest_common_substr(string &s1, string &s2){
    if(s1 == "" || s2 == "") return "";

    int m = s1.size();
    int n = s2.size();
    //m[i][j] indicates the length of common substring 
    //between substring of s1 ending at i
    //and substring of s2 ending at j
    vector<vector<int> > mat(m, vector<int>(n, 0));
    
    //record ending index of s1 for longest common substring
    int idx = -1;
    int len = 0;

    for(int j = 0; j < n; j++){
        if(s1[0] == s2[j]){
            mat[0][j] = 1;
        }
    }
    
    for(int i = 0; i < m; i++){
        if(s1[i] == s2[1]){
            mat[i][0] = 1;
            idx = i;
            len = 1;
        }
    }
    
    for(int i = 1; i < m; i++){
        for(int j = 1; j < n; j++){
            if(s1[i] == s2[j]){
                mat[i][j] = mat[i-1][j-1]+1;
                if(mat[i][j] > len){
                    len = mat[i][j];
                    idx = i;
                }
            }
            else{
                mat[i][j] = 0;
            }
        }
    }
    
    if(len > 0){
        return s1.substr(idx-len+1,len);
    }
    else{
        return "";
    }
}
