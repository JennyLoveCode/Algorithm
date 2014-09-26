/*
4. Find smallest element in cyclically array.
2, 4, 5, 1, 2, 3, 4, 5, 6
0  1  2  3  4  5  6  7  8

special case: 2 4 5 1 6
              2 1 3 5 6
*/

#include <iostream>
#include <vector>
using namespace std;

int Find(vector<int>);

int main(){
    int arr[] = {2,4,5,1,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> v(arr, arr+n);
    int res = Find(v);
    cout<<v[res]<<endl;
    return 0;
}

int Find(vector<int> v){
	int left = 0;
	int right =v.size()-1;
	int mid = -1;
	while(left < right){
		mid = left+(right - left)/2;
		if(v[mid] > v[right]) {
	        left = mid+1;
        }
        else{
	        right = mid;
        }
    }
    return mid;
}

/*
find non-monotone interval
*/