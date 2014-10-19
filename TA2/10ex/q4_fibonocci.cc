/*
 Write code to print the n th number of Fibonnaci number. 
*/
#include <iostream>
using namespace std;

int Fibonnaci(int n);
int Fib(int n);

int main(){
    int n = 3;
    int res1 = Fibonnaci(n);
    int res2 = Fib(n);
    cout<<"res1 "<<res1<<" res2: "<<res2<<endl;
    return 0;
}

int Fibonnaci(int n){
    int prev = 0;
    int cur = 1;
    if(n == 1){
        return prev;
    }
    if(n == 1){
        return cur;
    }
    for(int i = 2; i <= n; ++i){
        int t = cur;
        cur = prev+cur;
        prev = cur;
    }
    return cur;
}

int Fib(int n){
    //base case
    if(n == 0){
        return 0;
    } 
    if(n == 1){
        return 1;
    } 
    //recursive
    return Fib(n-1)+Fib(n-2);
}