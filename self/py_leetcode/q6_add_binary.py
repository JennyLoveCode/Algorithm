"""
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".

"""

def main():
    a = "11"
    b = "100"
    result = add_binary(a,b)
    print result

def add_binary(a, b):
    m = len(a)
    n = len(b)
    
    if m < n:
        return add_binary(b, a)
    
    sum = ['0' for i in range(m)]
    carry = '0'
    
    i = m-1
    j = n-1
    while j >= 0:
        if a[i] == '0' and b[j] == '0':
            sum[i] = carry
            carry = '0'
        elif a[i] == '1' and b[j] == '1':
            sum[i] = carry
            carry = '1'
        else:
            if carry == '0':
                sum[i] = '1'
            else:
                sum[i] = '0'
                carry = '1'
        i -= 1
        j -= 1
    
    while i >= 0:
        if a[i] == '0':
            sum[i] = carry
            carry = '0'
        else:
            if carry == '0':
                sum[i] = '1'
        i -= 1
    
    if carry == '0':
        return "".join(sum)
    else:
        return "1"+"".join(sum)

if __name__ == "__main__":
    main()