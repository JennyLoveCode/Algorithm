/*
Q31 How to determine whether an array C[] can be merged by A[] and B[]?
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool IsMerged(string &, string &, string &, int, int, int);
bool DPIsMerged(string & , string & , string &);

int main(){
    string A = "qwer";
    string B = "xyzt";
    string C = "xqwyzter";
    bool result;
    //recursion
    if(A.size()+B.size() != C.size()){
        result = false;
    }
    else{
        result = IsMerged(A,B,C,0,0,0);
    }
    //dp
    bool dp_result = DPIsMerged(A,B,C);
    if(result) cout<<"True -- Recursive"<<endl;
    else cout<<"False -- Recursive"<<endl;
    if(dp_result) cout<<"True -- DP"<<endl;
    else cout<<"False -- DP"<<endl;
    return 0;
}

bool IsMerged(string &A, string &B, string &C, int i, int j, int k){
    //base case
    if(i == A.size() && j == B.size() && k == C.size()){
        return true;
    }
    //recursive rule
    return (A[i] == C[k] && IsMerged(A,B,C,i+1, j, k+1)) || 
            (B[j] == C[k] && IsMerged(A,B,C, i, j+1, k+1));
}

bool DPIsMerged(string &A, string &B, string &C){
    if(A.size()+B.size() != C.size()) return false;
    vector<vector<bool> > table(A.size()+1, vector<bool>(B.size()+1, false));
    table[0][0] = true;
    for(int i = 1; i <= A.size(); i++){
        table[i][0] = table[i-1][0] && A[i-1] == C[i-1];
    }
    for(int j = 1; j <= B.size(); j++){
        table[0][j] = table[0][j-1] && B[j-1] == C[j-1];
    }
    for(int i = 1; i<= A.size(); i++){
        for(int j = 1; j <= B.size(); j++){
            table[i][j] = (table[i-1][j] && A[i-1] == C[i+j-1]) ||
                            (table[i][j-1] && B[j-1] == C[i+j-1]);
        }
    }
    return table[A.size()][B.size()];
}