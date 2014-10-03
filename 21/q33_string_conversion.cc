/*
Q33 (string conversion) “ A1B2C3D4” ==> “ABCD1234”
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
    string s = "A1B2C3D4E5F6G7H8I9";
    Convert(s);
    cout<<s<<endl;
    return 0;
}

void Convert(string &s){
    ConvertHelp(s, 0, s.size()-1);
}

void ConvertHelp(string &s, int begin, int end){
    //base case : two elements
    if(begin + 1 >= end){
        return;
    }
    //recursive rule
    int mid = begin+(end-begin)/2;
    //odd
    if(mid % 2 == 0) mid -= 1;
    ConvertHelp(s, begin, mid);
    ConvertHelp(s, mid+1, end);
    Rotate(s, mid - (mid-begin+1)/2 +1, mid, mid+1, mid+(end-mid)/2);
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