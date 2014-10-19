"""
Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, 
please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely 
(ie, no given input specs). You are responsible to gather all the 
input requirements up front.

Requirements for atoi:
The function first discards as many whitespace characters as necessary 
until the first non-whitespace character is found. 
Then, starting from this character, takes an optional initial plus or 
minus sign followed by as many numerical digits as possible, and interprets 
them as a numerical value.

The string can contain additional characters after those that form the 
integral number, which are ignored and have no effect on the behavior of 
this function.

If the first sequence of non-whitespace characters in str is not a valid 
integral number, or if no such sequence exists because either str is empty 
or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned. 
If the correct value is out of the range of representable values, 
INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.
"""
def main():
    str = "      -123456L89"
    result = atoi(str)
    print result

def atoi(str):
    #remove whitespace
    s = str.strip()
    #deal with sign
    sign = 1
    if s[0] == '+':
        s = s[1:]
    elif s[0] == '-':
        sign = -1
        s = s[1:]

    INT_MIN = -2147483648
    INT_MAX = 2147483647
    result = 0
    for c in s:
        if c.isdigit() == False:
            return result*sign
        num = ord(c) - ord('0')
        #check overflow
        check1 = result > INT_MAX/10
        check2 = result == INT_MAX/10 and num > INT_MAX%10
        if check1 or check2:
            if sign == 1:
                return INT_MAX
            else:
                return INT_MIN
        else:
            result = result*10+num

    return result*sign
            
if __name__ == "__main__":
    main()