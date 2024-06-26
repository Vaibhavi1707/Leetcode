#
# @lc app=leetcode id=1752 lang=python3
#
# [1752] Check if Array Is Sorted and Rotated
#

# @lc code=start
class Solution:
    def check(self, nums: List[int]) -> bool:
        peak = 0
        for i, _ in enumerate(nums[:-1]):
            if nums[i + 1] < nums[i]:
                peak += 1
        if peak not in [0, 1]:
            return False
        if peak == 1:
            return nums[-1] <= nums[0]
        return True
# @lc code=end

