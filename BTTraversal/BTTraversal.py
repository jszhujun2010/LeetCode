##This file is for binary tree traversal, in a iterative fashion

class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def preorderTraversal(self, root):
        nodeStack = []
        curNode = root
        while (nodeStack or curNode):
            if curNode:
                print curNode.val
                if curNode.right:
                    nodeStack.append(curNode.right)
                curNode = curNode.left
            else:
                curNode = nodeStack.pop()

    def inorderTraversal(self, root):
        nodeStack = []
        curNode = root
        while (nodeStack or curNode):
            if curNode:
                nodeStack.append(curNode)
                curNode = curNode.left
            else:
                curNode = nodeStack.pop()
                print curNode.val
                curNode = curNode.right

    def postorderTraversal(self, root):
        nodeStack = []
        curNode = root
        lastVisit = None
        while (nodeStack or curNode):
            if curNode:
                nodeStack.append(curNode)
                curNode = curNode.left
            else:
                peekNode = nodeStack[-1]
                if peekNode.right and peekNode.right != lastVisit:
                    curNode = peekNode.right
                else:
                    print peekNode.val
                    lastVisit = nodeStack.pop()
                
                
            
