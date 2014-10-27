/*
In the classic problem of the Towers of Hanoi, you have 3 rods and N disks of different sizes which 
can slide onto any tower. The puzzle starts with disks sorted in ascending order of size from top to 
bottom (e.g., each disk sits on top of an even larger one). You have the following constraints:

Only one disk can be moved at a time.
A disk is slid off the top of one rod onto the next rod.
A disk can only be placed on top of a larger disk.
Write a program to move the disks from the first rod to the last using Stacks
*/
#include <iostream>
#include <stack>
using namespace std;

struct op{
    int begin;
    int end;
    char src;
    char bri;
    char des;
    
    op(){}
    ~op(){}
    op(int b, int e, int src_, int bri_, int des_): begin(b), end(e), src(src_), bri(bri_), des(des_){}
};

void Hanoi(int n, char src, char bri, char des);
void hanoi(int n, char src, char bri, char des);

int main(){
    char src = 'A';
    char bri = 'B';
    char des = 'C';
    int n = 3;
    //Hanoi(n, src, bri, des);
    hanoi(n, src, bri, des);
    return 0;
}

void Hanoi(int n, char src, char bri, char des){
    //base case
    if(n == 1){
        cout<<"Move disk "<<n<<" from "<<src<<" to "<<des<<endl;
        return;
    }
    //recursive rule
    Hanoi(n-1, src, des, bri);
    cout<<"Move disk "<<n<<" from "<<src<<" to "<<des<<endl;
    Hanoi(n-1, bri, src, des);
}

void hanoi(int n, char src, char bri, char des){
    stack<op> s;
    s.push(op(1,n,src,bri,des));
    
    while(!s.empty()){
        op cur = s.top();
        s.pop();
        if(cur.begin != cur.end){
            s.push(op(cur.begin, cur.end-1, bri, src, des));
            s.push(op(cur.end, cur.end,src, bri, des));
            s.push(op(cur.begin, cur.end-1, src, des, bri));
        } else {
            cout<<"Move disk "<<cur.end<<" from "<<cur.src<<" to "<<cur.des<<endl;
        }
    }
}




