"""
Write a function to find the longest common prefix string amongst an array 
of strings.
"""

def main():
    arr = ["abc","abcdefg","abcffg","ab"]
    result = LongestPrefix(arr)
    print result

def LongestPrefix(arr):
    if len(arr) == 0:
        return None
    if len(arr) == 1:
        return arr[0]

    s = arr[0]
    for idx in range(len(s)):
        for i in range(1,len(arr)):
            if len(arr[i]) <= idx or arr[i][idx] != arr[0][idx]:
                return s[:idx]
    return arr[0] 

if __name__ == "__main__":
    main()