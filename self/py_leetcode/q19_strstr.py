"""
Returns a pointer to the first occurrence of needle in haystack, or null 
if needle is not part of haystack.

"""
def main():
    str = "apcacapplebdefc"
    s = "apple"
    idx = strstr(str,s)
    print idx

def strstr(str, s):
    n = len(str)
    m = len(s)
    i = 0
    #discard whitespace
    while str[i] == ' ':
        i += 1

    begin = i
    while begin <= n-m:
        i = begin
        j = 0
        while j < m and str[i] == s[j]:
            i += 1
            j += 1
        if j == m:
            return begin
        begin += 1
    
    return -1

if __name__ == "__main__":
    main()
