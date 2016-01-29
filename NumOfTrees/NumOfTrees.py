# num of BST

class Solution(object):
    def numTrees(self, n):
        """
        :type n: int
        :rtype: int
        """
        ## need some hints
        if n < 2:
            return n
        head = [0]*(n+1)
        head[0] = 1
        head[1] = 1
        for i in range(2, n+1):
            result = head[i-1]
            for j in range(1, i):
                result += head[j] * head[i-1-j]
            head[i] = result
        return head[-1]

sln= Solution()
print sln.numTrees(4)
