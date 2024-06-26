#
# @lc app=leetcode id=974 lang=python3
#
# [974] Subarray Sums Divisible by K
#

# @lc code=start

def find_prefix_sum(nums):
    prefix = [0]
    for num in nums:
        prefix.append(prefix[-1] + num)
    return prefix

class Solution:
    def subarraysDivByK(self, nums: List[int], k: int) -> int:
        prefix_sum = find_prefix_sum(nums)
        count = 0
        for i in range(len(prefix_sum)):
            for j in range(i + 1, len(prefix_sum)):
                if (prefix_sum[j] - prefix_sum[i]) % k == 0:
                    count += 1
        return count
# @lc code=end

