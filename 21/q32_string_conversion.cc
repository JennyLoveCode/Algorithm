/*
Q32 (string conversion) “AB | CD | 12 | 34” ==> “A1B2C3D4”
*/
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

void Convert(string &);
void ConvertHelp(string &, int , int );
void Rotate(string &, int , int , int , int );
void Reverse(string &, int , int );

int main(){
    string s = "ABCDEFGHI123456789";
    Convert(s);
    cout<<s<<endl;
    return 0;
}

void Convert(string &s){
    ConvertHelp(s, 0, s.size()-1);    
}

void ConvertHelp(string &s, int begin, int end){
    //base case
    if(begin + 3 > end){
        return;
    }
    //recursive rule
    int n = end-begin+1;
    int mid = begin+(end-begin)/2;
    Rotate(s, begin+n/4,mid,mid+1,mid+n/4);
    ConvertHelp(s, begin, begin+n/4+n/4-1);
    ConvertHelp(s, begin+n/4+n/4, end);
}

void Rotate(string &s, int begin1, int end1, int begin2, int end2){
    Reverse(s, begin1, end1);
    Reverse(s, begin2, end2);
    Reverse(s, begin1, end2);
}

void Reverse(string &s, int begin, int end){
    for(int i = begin, j = end; i < j; ++i, --j){
        swap(s[i], s[j]);
    }
}