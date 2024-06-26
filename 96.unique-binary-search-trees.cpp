/*
 * @lc app=leetcode id=96 lang=cpp
 *
 * [96] Unique Binary Search Trees
 */

// @lc code=start
class Solution {
public:
    int catalan(int n, vector<int>& dp) {
        if (n == 0) return 1;

        if (dp[n] != 1) return dp[n];

        long long res = 0;
        for (int i = 0; i < n; i++) {
            res += catalan(i, dp) * catalan(n - i - 1, dp); 
        }
        dp[n] = res;
        return res;
    }

    int numTrees(int n) {
        vector<int>dp(n + 1, 1);
        return catalan(n, dp);
    }
};
// @lc code=end

