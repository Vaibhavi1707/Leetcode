#
# @lc app=leetcode id=485 lang=python3
#
# [485] Max Consecutive Ones
#

# @lc code=start
class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        i = 0
        max_len = 0
        while i < len(nums):
            j = i
            start = i
            while j < len(nums) and nums[j] == 1:
                j += 1
            max_len = max(max_len, j - start)
            i = j + 1
        return max_len
# @lc code=end

