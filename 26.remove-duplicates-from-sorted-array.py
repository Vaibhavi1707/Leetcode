#
# @lc app=leetcode id=26 lang=python3
#
# [26] Remove Duplicates from Sorted Array
#

# @lc code=start
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        i = 0
        idx = 0
        while i < len(nums):
            while i < len(nums) - 1 and nums[i] == nums[i + 1]:
                i += 1
            if i < len(nums) - 1 and nums[i] != nums[i + 1]:
                nums[idx + 1] = nums[i + 1] 
                idx += 1
            i += 1
        return idx + 1
# @lc code=end

