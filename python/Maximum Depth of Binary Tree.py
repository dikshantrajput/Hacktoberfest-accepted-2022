O(n)

class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        if root == None:
            return 0
        
        left = self.maxDepth(root.left)
        right = self.maxDepth(root.right)
        return max(left,right)+1
        
class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        stack = []
        if root:
            stack.append((1,root))
        depth = 0
        while stack:
            curr_depth, root = stack.pop()
            if root:
                depth = max(curr_depth,depth)
                stack.append((curr_depth+1, root.left))
                stack.append((curr_depth+1, root.right))
        return depth