class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        maxx = -0x7f7f7f7f7f
        sums = 0
        for i in range(len(nums)):
            if sums+nums[i] <= 0:
                maxx = max(maxx,sums+nums[i])
                sums = 0
            else:
                sums += nums[i]
                maxx = max(maxx,sums)
        return maxx
