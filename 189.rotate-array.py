#
# @lc app=leetcode id=189 lang=python3
#
# [189] Rotate Array
#

# @lc code=start
class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        k = k % len(nums)
        i = 0
        while i < k:
            j = 0
            while i != (i + j * k) % len(nums):
                t = nums[i]
                nums[i] = nums[(i + j * k) % len(nums)]
                nums[(i + j * k) % len(nums)] = t
                j += 1
            i += 1
# @lc code=end

