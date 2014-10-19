class Node:
    def __init__(self,v,l,r):
        self.val = v
        self.left = l
        self.right = r

global max_sum

def main():
    max_sum = [0]
    n3 = Node(3, None, None)
    n4 = Node(4, None, None)
    root = Node(5, n3, n4)
    MaxSum(root, max_sum)
    print max_sum[0]

def MaxSum(root, max_sum):
    if root is None:
        return 0
    else:
        DFS(root, 0, max_sum)

def DFS(root, cur_sum, max_sum):
    if root is None:
        return
    if root.left is None and root.right is None:
        max_sum[0] = max(max_sum[0], cur_sum+root.val)
        return
    DFS(root.left, cur_sum+root.val, max_sum)
    DFS(root.right, cur_sum+root.val, max_sum)

if __name__ == "__main__":
    main()