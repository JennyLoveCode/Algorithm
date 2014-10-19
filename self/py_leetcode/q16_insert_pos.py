"""
Given a sorted array and a target value, return the index if the target is found. 
If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5  2
[1,3,5,6], 2  1
[1,3,5,6], 7  4
[1,3,5,6], 0  0

"""
def main():
    arr = [1,3,5,6]
    target = 0
    index = Find(arr, target)
    print index

def Find(arr, target):
    l = 0
    r = len(arr)-1
    
    while l <= r:
        mid = l+(r-l)/2
        if arr[mid] == target:
            return mid
        elif arr[l] > target:
            if l == 0:
                return 0
            else:
                return l-1
        elif arr[r] < target:
            return r+1
        elif arr[mid] > target:
            r = mid-1
        elif arr[mid] < target:
            l = mid+1

if __name__ == "__main__":
    main()