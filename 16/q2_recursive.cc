/*
Q2: (Array2) How Print two dimensional array in an spiral order. （NxN)
*/

#include <iostream>
using namespace std;

void spiral_print(int arr[][5], int offset, int size){
    //base case
    if(size <= 1){
        cout<<arr[offset][offset]<<endl;
        return;
    }
    //from left to right
    for(int j = 0; j < size; j++){
        cout<<arr[offset][offset+j]<<" ";
    }
    //from right top to right bottom
    for(int i = 1; i < size; i++){
        cout<<arr[offset+i][offset+size-1]<<" ";
    }
    //from right to left
    for(int j = 1; j < size; j++){
        cout<<arr[offset+size-1][offset+size-1-j]<<" ";
    }
    //from left bottom to left top
    for(int i = 1; i < size - 1; i++){
        cout<<arr[offset+size-1-i][offset]<<" ";
    }
    //recursive rule
    spiral_print(arr, offset+1, size-2);
}

int main(){
    int arr[5][5] = {
        {1,2,3,4,5},
        {6,7,8,9,10},
        {11,12,13,14,15},
        {16,17,18,19,20},
        {21,22,23,24,25}
    };
    
    int offset = 0;
    int size = 5;
    spiral_print(arr,offset,size);
}
