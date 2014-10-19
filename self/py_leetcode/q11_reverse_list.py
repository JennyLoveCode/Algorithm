""" reverse link list """
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
    
    #new_head = ReverseIt(head)
    new_head = ReverseRe(head)
    Print(new_head)

def ReverseIt(head):
    if head is None or head.next is None:
        return head
    
    prev = head
    cur = head.next
    
    while cur is not None:
        next_node = cur.next
        cur.next = prev
        prev = cur
        cur = next_node

    #update tail
    head.next = None
    return prev

def ReverseRe(head):
    #base case
    if head is None or head.next is None:
        return head
    #recursive rule
    new_head = ReverseRe(head.next)
    head.next.next = head
    head.next = None
    return new_head
    
def Print(head):
    cur = head
    while cur is not None:
        print cur.val
        cur = cur.next

if __name__ == "__main__":
    main()