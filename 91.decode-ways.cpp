/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 */

// @lc code=start
class Solution {
public:
    int decode(vector<int>& n, vector<int>& dp, int i) {
        if (i >= n.size()) return 1;

        if (dp[i] != -1) return dp[i];
        dp[i] = 0;        
        if (n[i] > 0) {
            dp[i] += decode(n, dp, i + 1);
        }

        if (i < n.size() - 1 && n[i] != 0 && n[i] * 10 + n[i + 1] <= 26) {
            dp[i] += decode(n, dp, i + 2);
        }


        return dp[i];
    }

    int numDecodings(string s) {
        vector<int> n;
        for (int i = 0; i < s.length(); i++) {
            n.push_back(s[i] - '0');
        }
        vector<int> dp(s.length(), -1);
        return decode(n, dp, 0);
    }
};
// @lc code=end

