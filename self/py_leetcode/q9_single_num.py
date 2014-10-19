"""
Given an array of integers, every element appears twice except for one. 
Find that single one.

Note:
Your algorithm should have a linear runtime complexity. 
Could you implement it without using extra memory?
"""
def main():
    arr = [1,2,3,4,5,4,1,3,2]
    result = SingleNum(arr)
    print result

def SingleNum(arr):
    result = arr[0]
    
    for num in arr[1:]:
        result ^= num
    
    return result

if __name__ == "__main__":
    main()