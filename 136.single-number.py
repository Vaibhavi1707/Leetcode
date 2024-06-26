#
# @lc app=leetcode id=136 lang=python3
#
# [136] Single Number
#

# @lc code=start
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        xor = 0
        for i in range(len(nums)):
            xor = xor ^ nums[i]
        return xor
# @lc code=end

