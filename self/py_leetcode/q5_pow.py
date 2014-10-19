""" Implement pow(x, n). """

def main():
    x = 2
    n = 0
    print pow(x, n)
    
def pow(x, n):
    if n < 0:
        return 1.0/power(x, -n)
    else:
        return power(x, n)

def power(x, n):
    #base case
    if n == 0:
        return 1
    #recursive rule
    tmp = pow(x, n/2)
    if n & 0x01 == 0:
        return tmp * tmp
    else:
        return x * tmp * tmp

if __name__ == "__main__":
    main()