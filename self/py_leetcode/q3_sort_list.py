"""
Sort a linked list using insertion sort.
"""
class ListNode:
    def __init__(self, v):
        self.val = v
        self.next = None

def main():
    head = ListNode(5)
    n1 = ListNode(1)
    n2 = ListNode(2)
    n3 = ListNode(3)
    n4 = ListNode(4)
    
    head.next = n4
    n4.next = n3
    n3.next = n2
    n2.next = n1
    
    result = sort_list(head)
    print_list(result)
    
def sort_list(head):
    #no node or only one node
    if head is None or head.next is None:
        return head

    #add dummy node before the head
    dummy = ListNode(-1)
    dummy.next = head
    
    prev = dummy
    cur = head
    while cur is not None:
        if cur.val >= prev.val:
            prev = cur
            cur = cur.next
        else:
            #detach cur node
            prev.next = cur.next
            #insert node
            pos = find_pos(dummy, cur)
            next = pos.next
            pos.next = cur
            cur.next = next
            #update cur
            cur = prev.next
    
    return dummy.next

def find_pos(dummy, node):
    prev = dummy
    cur = dummy.next

    while cur is not None:
        if cur.val >= node.val:
            break
        else:
            prev = cur
            cur = cur.next

    return prev

def print_list(head):
    cur = head

    while cur is not None:
        print cur.val
        cur = cur.next
    
if __name__ == "__main__":
    main()