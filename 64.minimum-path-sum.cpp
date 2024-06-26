/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 */

// @lc code=start
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<long long>> dp(m, vector<long long>(n, INT_MAX));
        dp[m - 1][n - 1] = grid[m - 1][n - 1];
        for (int i = m - 1; i >= 0; i --) {
            for (int j = n - 1; j >= 0; j --) {
                if (i < m - 1) {
                    dp[i][j] = min(dp[i][j], grid[i][j] + dp[i + 1][j]);
                }
                if (j < n - 1) {
                    dp[i][j] = min(dp[i][j], grid[i][j] + dp[i][j + 1]);
                }
            }
        }
        return dp[0][0];
    }
};
// @lc code=end

