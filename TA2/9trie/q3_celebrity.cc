/*
3. Celebrity is a person who does not know everyone, but everyone else knows him. 
We give a 2-D array integer array, if A knows B, then matrix[A][B] is 1. Otherwise, 0. 
How we find out the celebrity.				
	mat[i][j] == 1		i is not celebrity
	i -> j  == 0		j is not celebrity
	0   1     2    3   4 ….. n
	i    i	 i     j
*/
#include <iostream>
using namespace std;

int FindCelebrity(int mat[][5],int );

int main(){
    //2 is celebrity
    int mat[][5] = {
                    {0,0,1,1,0},
                    {0,0,1,1,0},
                    {0,0,0,0,0},
                    {1,1,1,0,0},
                    {0,0,1,0,0}
                };
    int n = 5;
    int celebrity = FindCelebrity(mat,n);
    cout<<celebrity<<endl;
    return 0;  
}

int FindCelebrity(int mat[][5],int n){
    int i = 0;
    int j = 1;
    while(j < n){
        //if i knows j, i is not celebrity
        if(mat[i][j] == 1){
            i = j;
        }
        j++;
    }
    return i;
}