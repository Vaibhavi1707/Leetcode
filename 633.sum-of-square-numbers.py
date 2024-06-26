#
# @lc app=leetcode id=633 lang=python3
#
# [633] Sum of Square Numbers
#

# @lc code=start
from math import sqrt,ceil

class Solution:
    def judgeSquareSum(self, c: int) -> bool:
        if c == 0:
            return True
        
        for a in range(ceil(sqrt(c))):
            b_2 = sqrt(c - (a ** 2))
            
            if b_2 == int(b_2):
                return True
        return False
# @lc code=end

