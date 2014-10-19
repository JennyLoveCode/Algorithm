"""
There are two sorted arrays A and B of size m and n respectively. 
Find the median of the two sorted arrays. The overall run time complexity 
should be O(log (m+n)).
"""

def main():
    A = [1,3,4,5,7,8]
    B = [3,5,9,11]
    m = len(A)
    n = len(B)
    total = m+n

    if total & 0x01 == 1:
        print find_kth(A,m,B,n,total/2+1)
    else:
        res = ( find_kth(A,m,B,n,total/2) + find_kth(A,m,B,n,total/2+1) ) /2
        print res        

def find_kth(A, m, B, n, k):
    #base case
    if(m > n):
        return find_kth(B,n,A,m,k)
    if(m == 0):
        return B[k-1]
    if(k == 1):
        return min(A[0], B[0])
    
    pa = min(k/2, m)
    pb = k - pa
    #discard the left pa part of A
    if(A[pa-1] < B[pb-1]):
        return find_kth(A[pa:], m-pa, B, n, k-pa)
    elif(A[pa-1] > B[pb-1]):
        return find_kth(A, m, B[pb:], n-pb, k-pb)
    else:
        return A[pa-1]

if __name__ == "__main__":
    main()