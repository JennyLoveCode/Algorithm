/*
7.  Given n pairs of parentheses, write a function to print all combinations of 
well-formed parentheses.
*/
#include <iostream>
#include <string>
using namespace std;

void Generate(string , int , int , int );

int main(){
    int n =3;
    generate("", n, 0, 0);
    return 0;
}

void Generate(string output, int n, int left, int right){
    //base case
    if(left == n){
        cout<<output.append(n-right,')')<<endl;
        return;
    } 
    //recursive rule
    Generate(output+'(', n, left+1, right);
    if(left > right){
        Generate(output+')', n, left, right+1);
    }
}
