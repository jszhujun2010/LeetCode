##binary search

class Solution(object):
    def searchInsert(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        if target < nums[0]:
            return 0
        if target > nums[-1]:
            return len(nums)
        left = 0
        right = len(nums)-1
        while left <= right:
            mid = (left+right) / 2
            if nums[mid] == target:
                return mid
            elif nums[mid] < target:
                left = mid + 1
            else:
                right = mid - 1
        if nums[mid] < target:
            return mid + 1
        else:
            return mid

sln = Solution()
l = [1, 3, 5, 6, 7]
print sln.searchInsert(l, 1)
print sln.searchInsert(l, 2)
print sln.searchInsert(l, 3)
print sln.searchInsert(l, 4)
print sln.searchInsert(l, 5)
print sln.searchInsert(l, 6)
print sln.searchInsert(l, 7)
print sln.searchInsert(l, 8)
