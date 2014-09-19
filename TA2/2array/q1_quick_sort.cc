/*
1.Can you explain Quick sort.
*/
#include <iostream>
#include <vector>
using namespace std;

void QuickSort(vector<int> & , int, int);
int Partition(vector<int> &, int , int);
void Swap(int &, int &);
void Print(vector<int> &);

int main(){
    int arr[] = {4,2,3,6,8,5,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> v(arr, arr+n);
    QuickSort(v, 0, n-1);
    Print(v);
    return 0;
}

void QuickSort(vector<int> &v, int l, int h){
    if(l < h){
        int p = Partition(v, l, h);
        QuickSort(v, l, p-1);
        QuickSort(v, p+1, h);
    }
}

int Partition(vector<int> &v, int l, int h){
    int pivot = v[h];
    int i = l-1;
    for(int j = l; j < h; j++){
        if(v[j] <= pivot){
            i++;
            swap(v[i], v[j]);
        }
    }
    i++;
    swap(v[i], v[h]);
    return i;
}

void Swap(int &a, int &b){
    int tmp = a;
    a = b;
    b = tmp;
    return;
}

void Print(vector<int> &v){
    for(int i = 0; i < v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return;
}

/*
Like Merge Sort, QuickSort is a Divide and Conquer algorithm. It picks an element 
as pivot and partitions the given array around the picked pivot. There are many 
different versions of quickSort that pick pivot in different ways.
1) Always pick first element as pivot.
2) Always pick last element as pivot (implemented below)
3) Pick a random element as pivot.
4) Pick median as pivot.

The key process in quickSort is partition(). Target of partitions is, given an array 
and an element x of array as pivot, put x at its correct position in sorted array and 
put all smaller elements (smaller than x) before x, and put all greater elements 
(greater than x) after x. All this should be done in linear time.

Partition Algorithm
There can be many ways to do partition, following code adopts the method given 
in CLRS book. The logic is simple, we start from the leftmost element and keep 
track of index of smaller (or equal to) elements as i. While traversing, if we 
find a smaller element, we swap current element with arr[i]. Otherwise we ignore 
current element.
*/