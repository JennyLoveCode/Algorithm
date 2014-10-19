"""
You are given two linked lists representing two non-negative numbers. 
The digits are stored in reverse order and each of their nodes 
contain a single digit. Add the two numbers and return it 
as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
"""
class ListNode:
    def __init__(self, v):
        self.val = v
        self.next = None

def main():
    a = ListNode(2)
    b = ListNode(5)
    n1 = ListNode(4)
    n2 = ListNode(3)
    n3 = ListNode(6)
    n4 = ListNode(4)

    a.next = n1
    n1.next = n2
    b.next = n3
    n3.next = n4
    
    Print(a)
    print "========"
    Print(b)
    
    sum = Add(a, b)
    print "========="
    Print(sum)

def Add(a, b):
    if a is None:
        return b
    if b is None:
        return a

    l1 = Reverse(a)
    l2 = Reverse(b)
    
    sum = 0
    carry = 0
    cur = None
    
    result = ListNode(-1)
    
    while l1 is not None or l2 is not None:
        sum = carry
        if l1 is not None:
            sum += l1.val
            l1 = l1.next
        if l2 is not None:
            sum += l2.val
            l2 = l2.next
        carry = sum / 10
        sum %= 10
        if cur is None:
            cur = ListNode(sum)
            result.next = cur
        else:
            cur.next = ListNode(sum)
            cur = cur.next
    
    if carry > 0:
        cur.next = ListNode(carry)
    
    head = Reverse(result.next)
    return head

def Reverse(node):
    if node is None or node.next is None:
        return node
    
    prev = node
    cur = prev.next
    
    while cur is not None:
        #change pointers
        next_node = cur.next
        cur.next = prev
        prev = cur
        cur = next_node
    node.next = None
    return prev

def Print(node):
    cur = node
    while cur is not None:
        print cur.val
        cur = cur.next  

if __name__ == "__main__":
    main()  