"""
Given a binary tree and a sum, determine if the tree has a root-to-leaf path 
such that adding up all the values along the path equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  6
         /  \      \
        7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
"""
class Node:
    def __init__(self, v):
        self.val = v
        self.left = None
        self.right = None

def main():
    root = Node(5)
    n4 = Node(4)
    n8 = Node(8)
    n11 = Node(11)
    n13= Node(13)
    n6= Node(6)
    n7 = Node(7)
    n2 = Node(2)
    n1 = Node(1)
    
    root.left = n4
    root.right = n8
    n4.left = n11
    n11.left = n7
    n11.right = n2
    n8.left = n13
    n8.right = n6
    n6.right = n1
    
    sum = 22
    
    if HasPath(root, sum):
        print "true"
    else:
        print "false"

def HasPath(root, sum):
    #base case
    if root is None:
        return False
    #leaf node
    if root.left is None and root.right is None:
        return sum == root.val
    #recursive rule
    return HasPath(root.left, sum-root.val)\
        or HasPath(root.right, sum-root.val)

if __name__ == "__main__":
    main()