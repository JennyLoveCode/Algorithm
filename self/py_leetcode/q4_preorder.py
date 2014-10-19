"""
Given a binary tree, return the preorder traversal of its nodes' values.

"""
class TreeNode:
    def __init__(self, v):
        self.val = v
        self.left = None
        self.right = None

def main():
    root = TreeNode(0)
    n1 = TreeNode(1)
    n2 = TreeNode(2)
    n3 = TreeNode(3)
    n4 = TreeNode(4)
    n5 = TreeNode(5)
    n6 = TreeNode(6)
    
    root.left = n1
    root.right = n2
    n1.left = n3
    n1.right = n4
    n2.left = n5
    n2.right = n6
    
    preorder_recursive(root)
    print "================"
    preorder(root)

def preorder_recursive(root):
    if root is None:
        return
    print root.val
    preorder_recursive(root.left)
    preorder_recursive(root.right)

def preorder(root):
    if root is None:
        return

    nodeStack = list()
    nodeStack.append(root)
    
    while len(nodeStack) > 0:
        cur = nodeStack.pop()
        print cur.val
        if cur.right is not None:
            nodeStack.append(cur.right)
        if cur.left is not None:
            nodeStack.append(cur.left)

if __name__ == "__main__":
    main() 