"""
Given a sorted array, remove the duplicates in place such that each element 
appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with 
constant memory.

For example,
Given input array A = [1,1,2],

Your function should return length = 2, and A is now [1,2].
"""

def main():
    arr = [1,1,2,3,4,4,4,4,5,5,6,7]
    result = RemoveDup(arr)
    Print(result)

def RemoveDup(arr):
    n = len(arr)
    if n <= 1:
        return arr

    i = 0
    j = 1
    
    while j < n:
        if arr[i] != arr[j]:
            arr[i+1] = arr[j]
            i += 1
        j += 1
    arr = arr[:i+1]
    return arr

def Print(arr):
    for i in arr:
        print i

if __name__ == "__main__":
    main()
    