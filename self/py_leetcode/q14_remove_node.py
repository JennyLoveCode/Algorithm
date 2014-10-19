"""
Given a linked list, remove the nth node from the end of list and return its head.

"""
class ListNode:
    def __init__(self, v):
        self.val = v
        self.next = None

def main():
    head = ListNode(0)
    n1 = ListNode(1)
    n2 = ListNode(2)
    n3 = ListNode(3)
    n4 = ListNode(4)
    n5 = ListNode(5)

    head.next = n1
    n1.next = n2
    n2.next = n3
    n3.next = n4
    n4.next = n5
    
    k = 4
    new_head = Remove(head, k)
    Print(new_head)

def Remove(head, n):
    slow = head
    fast = head
    while n > 0:
        if fast is None:
            return head
        fast = fast.next
        n -= 1
    
    while fast.next is not None:
        slow = slow.next
        fast = fast.next
    
    #delete node after slow node
    slow.next = slow.next.next
    return head

def Print(head):
    cur = head
    while cur is not None:
        print cur.val
        cur = cur.next

if __name__ == "__main__":
    main()