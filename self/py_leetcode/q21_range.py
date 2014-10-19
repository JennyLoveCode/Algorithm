"""
Given a sorted array of integers, find the starting and ending position of 
a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].

"""

def main():
    arr = [5,7,7,8,8,8,8,10]
    target = 8
    Range(arr, target)

def Range(arr, target):
    left = LeftBoard(arr, target)
    right = RightBoard(arr, target)
    print "range is [ %d , %d ]" % (left, right)

def LeftBoard(arr, target):
    left = 0
    right = len(arr)-1
    while left < right-1:
        mid = left+(right-left)/2
        if arr[mid] == target:
            #continue
            right = mid
        elif arr[mid] < target:
            left = mid+1
        else:
            right = mid-1
    #check : left first
    if arr[left] == target:
        return left
    if arr[right] == target:
        return right
    return -1

def RightBoard(arr, target):
    left = 0
    right = len(arr)-1

    while left < right-1:
        mid = left+(right-left)/2
        if arr[mid] == target:
            #continue
            left = mid
        elif arr[mid] < target:
            left = mid+1
        else:
            right = mid-1

    #check : right first
    if arr[right] == target:
        return right
    if arr[left] == target:
        return left
    return -1

if __name__ == "__main__":
    main()
            