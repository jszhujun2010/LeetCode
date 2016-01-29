class Solution(object):
    def combinationSum3(self, k, n):
        """
        :type k: int
        :type n: int
        :rtype: List[List[int]]
        """
        return list(self.combination(k, n, range(1,10)))


    def combination(self, k, n, left):
        if k == 1 and n in left:
            yield [n]

        for i in range(len(left)):
            for rest in self.combination(k-1, n-left[i], left[i+1:]):
                rest.insert(0, left[i])
                yield rest

sln = Solution()
print sln.combinationSum3(3, 9)
