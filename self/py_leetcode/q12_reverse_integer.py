"""
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321

Have you thought about this?
Here are some good questions to ask before coding. Bonus points for you 
if you have already thought through this!

If the integer's last digit is 0, what should the output be? ie, cases 
such as 10, 100.

Did you notice that the reversed integer might overflow? Assume the 
input is a 32-bit integer, then the reverse of 1000000003 overflows. 
How should you handle such cases?

Throw an exception? Good, but what if throwing an exception is not 
an option? You would then have to re-design the function 
(ie, add an extra parameter).
"""
import sys

def main():
    num = -1235678
    result = Reverse(num)
    print result

def Reverse(num):
    #check positive or negative num
    sign = 1
    if num < 0:
        sign = -1
        num = -num

    result = 0
    while num > 0:
        digit = num % 10
        num /= 10
        #check overflow
        check1 = result/10 == sys.maxint/10
        check2 = digit > sys.maxint%10
        check = check1 and check2
        if result/10 > sys.maxint/10 or check:
            return sys.maxint*sign
        result = result*10+digit
    
    return result*sign

if __name__ == "__main__":
    main()