/*
 4. Longest palindrome substring in a string. 
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int LongestPalindromeSub(string);

int main(){
    string str = "babcecbac";
    int len = LongestPalindromeSub(str);
    cout<<len<<endl;
    return 0;
}

int LongestPalindromeSub(string str){
    int n = str.size();
    vector<vector<bool> > check(n, vector<bool>(n, false));
    int max_len = 1;
    //base case: single character
    for(int i = 0; i < n; i++){
        check[i][i] = true;
    }
    //base case: adjacent two characters
    for(int i = 0; i < n-1; i++){
        if(str[i] == str[i+1]){
            check[i][i+1] = true;
            max_len = 2;
        }
    }
    //dp
    for(int k = 2; k < n; k++){
        for(int i = 0; i < n; i++){
            if(i+k >= n) continue;
            check[i][i+k] = check[i+1][i+k-1] && (str[i] == str[i+k]);
            if(check[i][i+k]){
                max_len = max(max_len, k+1);
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout<<check[i][j]<<" ";
        }
        cout<<endl;
    }
    return max_len;
}

/*中间开花 ： odd and even */