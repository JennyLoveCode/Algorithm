/*
1 In an int array A, find the minimum distance of two values a and b,
distance = |a’s index - b’s index|.

Example:
A = {1, 2, 3, 4, 3, 1, 5, 6, 1}
a = 1, b = 3
the distance between 1 and 3 = 1(pick the 3 at index 4 and the 1 at index 5).
*/
#include <iostream>
using namespace std;

int MinDist(int[], int, int, int);

int main(){
    int arr[] = {1,2,3,4,3,1,5,6,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int a = 3;
    int b = 1;
    int result = MinDist(arr, n, a, b);
    cout<<result<<endl;
    return 0;
}

int MinDist(int arr[], int n, int a, int b){
    int idx_a = -1;
    int idx_b = -1;
    int min_len = INT_MAX;

    for(int i = 0; i < n; ++i){
        //update a index
        if(arr[i] == a){
            idx_a = i;
            //update min_len
            if(idx_b >= 0){
                min_len = min(abs(idx_a-idx_b), min_len);
            }
        }
        //update b index
        else if(arr[i] == b){
            idx_b = i;
            //update min_len
            if(idx_a >= 0){
                min_len = min(abs(idx_a-idx_b), min_len);
            }
        }
    }
    return min_len;
}