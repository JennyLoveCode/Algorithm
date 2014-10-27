/*
String containing only ‘a’ or ‘b’, for example, “aaabbab”. we want to replace some of the ‘a’ with ‘b’ 
and/or some of the ‘b’ with ‘a’, so that the result String has all ‘a’s at the left side and all ‘b’s 
at right side.
What is the minimum number of replacements?

“aaabbab” → replace the last ‘a’ with ‘b’ → “aaabbbb”
“abaabbbabab”
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int Replacement(string s);

int main () {
    string s = "abaabbbab";
    int res = Replacement(s);
    cout<<res<<endl;
    return 0;
}

int Replacement(string s){
    int n = s.size();
    vector<int> left(n, 0);
    vector<int> right(n, 0);
    
    for(int i = 1; i < n; ++i){
        //build left
        if (s[i-1] == 'a') {
            left[i] = left[i-1];
        } else {
            left[i] = left[i-1] + 1;
        }
        //build right
        if (s[n-1-i] == 'b') {
            right[n-1-i] = right[n-i];
        } else {
            right[n-1-i] = right[n-i] + 1;
        }
    }
    
    int res = INT_MAX;
    for (int i = 0; i < n; ++i) {
        res = min(res, left[i]+right[i]);
    }
    return res;
}

/*
treat each element as a pivot when traversing
count how many replacement in left and right separately
pick one whose sum of left and right replacement is minimum
*/