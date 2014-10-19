"""
Given two binary trees, write a function to check if they are equal or not.

Two binary trees are considered equal if they are structurally identical 
and the nodes have the same value.
"""
class Node:
    def __init__(self, v):
        self.val = v
        self.left = None
        self.right = None

def main():
    p = Node(0)
    q = Node(0)
    n1 = Node(1)
    n2 = Node(2)
    n3 = Node(1)
    n4 = Node(2)

    p.left = n1
    p.right = n2
    q.left = n3
    #q.right = n4
    
    if Same(p,q):
        print "True"
    else:
        print "False"

def Same(p, q):
    #base case
    if p is None and q is None:
        return True
    if p is None or q is None:
        return False

    #recursive rule
    return p.val == q.val \
        and Same(p.left, q.left) \
        and Same(p.right, q.right)

if __name__ == "__main__":
    main()