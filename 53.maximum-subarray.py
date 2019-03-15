class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        res = nums[0]
        maxhere = nums[0]
        for k, v in enumerate(nums):
            if k == 0:
                continue

            maxhere = max(v, maxhere + v)
            res = max(res, v, maxhere)

        return res
