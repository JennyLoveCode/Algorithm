/*
5. Giving an positive integer k, compute square root, 
*/
#include <iostream>
using namespace std;

int SquareRoot(int);

int main(){
    int target = 101;
    int result = SquareRoot(target);
    cout<<result<<endl;
    return 0;
}

int SquareRoot(int target){
    int low = 1;
    int high = target;
    int last_mid;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(target/mid == mid){
            return mid;
        }
        else if(mid > target/mid){
            high = mid-1;
        }
        else{
            low = mid+1;
            last_mid = mid;
        }
    }
    return last_mid;
}