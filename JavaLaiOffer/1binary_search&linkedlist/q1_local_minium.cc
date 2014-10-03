/*
1 int[] array, unsorted, local minimum
*/
#include <iostream>
using namespace std;

int FindLocalMin(int[], int);

int main(){
    int arr[] = {9,6,5,2,8,9,11, 18, 21};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"n "<<n<<endl;
    int result = FindLocalMin(arr, n);
    cout<<result<<endl;
    return 0;
}

int FindLocalMin(int arr[], int n){
    int left = 0;
    int right = n-1;
    while(left < right){
        int mid = left+(right-left)/2;
        cout<<"mid is "<<arr[mid]<<endl;
        if((mid-1<0||arr[mid-1]>=arr[mid]) && (mid+1>=n||arr[mid+1]>=arr[mid])){
            return arr[mid];
        }
        //discard right part
        else if(arr[mid-1] < arr[mid]){
            right = mid-1;
        }
        //discard left part
        else{
            left = mid+1;
        }
    }
    return arr[left];
}