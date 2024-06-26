#
# @lc app=leetcode id=523 lang=python3
#
# [523] Continuous Subarray Sum
#

# @lc code=start

def get_prefix_sum(nums):
    for i, num in enumerate(nums[:-1]):
        nums[i + 1] += nums[i]
    nums.insert(0, 0)
    return nums
    

class Solution:
    def checkSubarraySum(self, nums: List[int], k: int) -> bool:
        if len(nums) < 2:
            return False
        
        prefix_sum = get_prefix_sum(nums)
        
        # we need to check the divisibility of the subarray sum
        # the subarray sum is difference between two elements of the prefix sum array
        # we need to find the remainders of each element of the prefix Sum Array
        
        mod_dict = {}
        for i, s in enumerate(prefix_sum):
            if s % k in mod_dict:
                if i - mod_dict[s % k] >= 2:
                    return True
            else:
                mod_dict[s % k] = i
        return False
        
# @lc code=end

