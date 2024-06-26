#
# @lc app=leetcode id=283 lang=python3
#
# [283] Move Zeroes
#

# @lc code=start
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        p1 = 0
        p2 = 0
        while p1 < len(nums):
            while nums[p2] == 0:
                p2 += 1
            t = nums[p1]
# @lc code=end

