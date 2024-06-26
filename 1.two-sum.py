#
# @lc app=leetcode id=1 lang=python3
#
# [1] Two Sum
#

# @lc code=start
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        elem2ind = {}
        
        for i in range(len(nums)):
            if nums[i] not in elem2ind:
                elem2ind[nums[i]] = []
            elem2ind[nums[i]].append(i)
            
        for i, num in enumerate(nums):
            if target - num in elem2ind:
                if target - num == num:
                    if len(elem2ind[num]) == 1:
                        continue
                    else:
                        return [i, elem2ind[num][-1]]
                else:
                    return [i, elem2ind[target - num][0]]
            
# @lc code=end

