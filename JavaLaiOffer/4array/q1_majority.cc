/*
Majority Number
There is one number in a sized N array that exists > N / 2 times, how do you find the number?
*/
#include <iostream>
using namespace std;

int FindMajority2(int[], int);
int FindMajority3(int[], int);

int main(){
    int arr[] = {1,2,5,3,2,2,8,9,11};
    int n = sizeof(arr)/sizeof(arr[0]);

    int majority2 = FindMajority2(arr, n);
    if(majority2 != INT_MIN){
        cout<<"Majority > n/2 is "<<majority2<<endl; 
    }
    else{
        cout<<"There is no majority exists > n/2. "<<endl;
    }

    int majority3 = FindMajority3(arr, n);
    if(majority3 != INT_MIN){
        cout<<"Majority > n/3 is "<<majority3<<endl; 
    }
    else{
        cout<<"There is no majority exists > n/3. "<<endl;
    }
    
    return 0;
}

int FindMajority2(int arr[], int n){
    int count = 0;
    int candidate;
    for(int i = 0; i < n; ++i){
        //update candidate
        if(count == 0){
            candidate = arr[i];
            count++;
            continue;
        }
        if(arr[i] == candidate){
            count++;
        }
        else{
            count--;
        }
    }
    //check
    count = 0;
    for(int i = 0; i < n; ++i){
        if(arr[i] == candidate){
            count++;
        }
    }
    if(count > n/2){
        return candidate;
    }
    else{
        return INT_MIN;
    }
}

int FindMajority3(int arr[], int n){
    int count1 = 0;
    int candidate1;
    int count2 = 0;
    int candidate2;
    
    //prepare candidates for majority
    for(int i = 0; i < n; ++i){
        //update candidates first
        if(count1 == 0){
            candidate1 = arr[i];
            count1++;
            continue;
        }
        if(count2 == 0){
            candidate2 = arr[i];
            count2++;
            continue;
        }
        //update count
        if(arr[i] == candidate1){
            count1++;
        }
        else if(arr[i] == candidate2){
            count2++;
        }
        else{
            count1--;
            count2--;
        }  
    }
    //check two candidates
    count1 = 0;
    count2 = 0;
    for(int i = 0; i < n; ++i){
        if(arr[i] == candidate1){
            count1++;
            continue;
        }
        if(arr[i] == candidate2){
            count2++;
            continue;
        }
    }
    if(count1 > n/3){
        return candidate1;
    }
    else if(count2 > n/3){
        return candidate2;
    }
    else{
        return INT_MIN;
    }
}