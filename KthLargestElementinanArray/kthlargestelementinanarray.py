#find the kth largest elem


class Solution(object):
    def findKthLargest(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        piviot = nums[0]
        larger = [x for x in nums if x > piviot]
        equal = [x for x in nums if x == piviot]
        smaller = [x for x in nums if x < piviot]

        if k <= len(larger):
            return self.findKthLargest(larger, k)
        elif k > len(larger)+len(equal):
            return self.findKthLargest(smaller, k-len(larger)-len(equal))
        else:
            return equal[0]

nums = [6,5,4,3,2,1]
sln = Solution()
print sln.findKthLargest(nums, 3)
