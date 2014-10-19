"""
Given a string, find the length of the longest substring without repeating 
characters. For example, the longest substring without repeating letters for 
"abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring 
is "b", with the length of 1.

"""
def main():
    s = "gaabcdefg"
    result = LongestSubstr(s)
    print result

def LongestSubstr(s):
    if len(s) <= 1:
        return len(s)
    
    cur_len = 1
    max_len = 1
    visited = dict()
    
    #initialize dictionary
    for c in s:
        visited[c] = None

    visited[s[0]] = 0

    for i in range(1, len(s)):
        prev_idx = visited[s[i]]
        
        #no repeating or this duplicated character is not in range of current substring
        if prev_idx is None or i-cur_len > prev_idx:
            cur_len += 1
        else:
            cur_len = i-prev_idx
            max_len = max(cur_len, max_len)

        #update dictionary
        visited[s[i]] = i

    #update max_len
    max_len = max(cur_len, max_len)
    return max_len
 
if __name__ == "__main__":
    main()