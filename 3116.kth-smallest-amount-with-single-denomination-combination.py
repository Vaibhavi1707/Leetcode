#
# @lc app=leetcode id=3116 lang=python3
#
# [3116] Kth Smallest Amount With Single Denomination Combination
#

# @lc code=start

def find_lcm(num1, num2):
    if(num1>num2):
        num = num1
        den = num2
    else:
        num = num2
        den = num1
    rem = num % den
    while(rem != 0):
        num = den
        den = rem
        rem = num % den
    gcd = den
    lcm = int(int(num1 * num2)/int(gcd))
    return lcm

def list_lcm(l):
    num1 = l[0]
    num2 = l[1]
    lcm = find_lcm(num1, num2)

    for i in range(2, len(l)):
        lcm = find_lcm(lcm, l[i])
    return lcm
    
class Solution:
    def findKthSmallest(self, coins: List[int], k: int) -> int:
        coins.sort()
        first_est = k * min(coins)
        
        vals = []
        lcm_so_far = coins[0]
        for idx, coin in enumerate(coins):
            i = 1
            while coin * i < first_est:
                lcm_so_far = find_lcm(lcm_so_far, coin)
                print(vals, coin, coin * i, i, lcm_so_far)
                if idx > 0 and coin * i % lcm_so_far != 0:
                    vals.append(coin * i)
                elif idx == 0:
                    vals.append(coin * i)
                i += 1
        vals = sorted(vals)
        print(vals)
        return first_est if len(vals) < k else vals[k - 1]
# @lc code=end

