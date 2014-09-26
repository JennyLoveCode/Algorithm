/*
Q6 Given a string, return the longest substring that contains at most two (k???) type 
of characters. 
abbbbbbbcbaa   
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

string LongestSubType(string , int );

int main(){
    string str = "abbbbbbbcbaa";
    int k = 3;
    string result = LongestSubType(str, k);
    cout<<result<<endl;
    return 0;
}

string LongestSubType(string str, int k){
    int n = str.size();
    vector<vector<string> > v(n, vector<string>(n,""));
    //store starting and ending index of longest substring with at most k characters
    vector<int> solu(2, -1);
    string res;
    int max_len = 0;
    //Initialization
    for(int i = 0; i < str.size(); ++i){
        v[i][i] = str[i];
    }

    for(int step = 1; step < str.size(); ++step){
        for(int i = 0; i < str.size(); ++i){
            int j = i+step;
            if(j >= str.size() || v[i][j-1].size() > k) continue;
            //get valid index in matrix and decrease some useless checking
            //char not exist in substring
            if(v[i][j-1].find(str[j]) == string::npos){
                v[i][j] = v[i][j-1]+str[j];
            } 
            else{
                v[i][j] = v[i][j-1];
            } 
            if(v[i][j].size() == k && j-i+1 > max_len){
                max_len = j-i+1;
                solu[0] = i;
                solu[1] = j;
            }             
        }
    }
    res = str.substr(solu[0],solu[1]-solu[0]+1);
    return res;
}

/*
mat[i][j] <==> string s
stands for the # of character in the substring starting at index i and ending at index j
string s is composed of different  characters in the substring

mat[i][j] 
= mat[i][j-1] if str[i] in s
= mat[i][j-1]+1 if not  ==> count++, s+str[i-1]

mat[i][j]
*/
