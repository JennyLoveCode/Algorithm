"""
Given an array of integers, find two numbers such that they add up to a specific 
target number.

The function twoSum should return indices of the two numbers such that they 
add up to the target, where index1 must be less than index2. Please note that 
your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2

"""
def main():
    num = [2,7,11,15]
    target = 9
    result = two_sum(num, target)
    for idx in result:
        print idx

def two_sum(num, target):
    numbers = sorted(num)
    left = 0
    right = len(numbers) - 1
    idx = list()
    
    while left < right:
        if numbers[left] + numbers[right] == target:
            idx.append(left+1)
            idx.append(right+1)
            break
        elif numbers[left] + numbers[right] < target:
            left += 1
        else:
            right -= 1
    
    result = tuple(idx)
    return result

if __name__ == "__main__":
    main()