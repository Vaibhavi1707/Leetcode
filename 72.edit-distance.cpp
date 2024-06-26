/*
 * @lc app=leetcode id=72 lang=cpp
 *
 * [72] Edit Distance
 */

// @lc code=start
class Solution {
public:

    int editDistance(string &word1, string &word2, vector<vector<int>>& memo, int m, int n) {
        if (m == 0) {
            memo[m][n] = n;
            return n;
        }
        if (n == 0) {
            memo[m][n] = m;
            return m;
        }
        if (memo[m][n] != -1) return memo[m][n];
        if (word1[m - 1] == word2[n - 1]) {
            memo[m][n] = editDistance(word1, word2, memo, m - 1, n - 1);
            return memo[m][n];
        }
        memo[m][n] = min(min(1 + editDistance(word1, word2, memo, m - 1, n - 1), // edit
                    1 + editDistance(word1, word2, memo, m, n - 1)), // insert
                    1 + editDistance(word1, word2, memo, m - 1, n)); // delete
        return memo[m][n];
    }

    int minDistance(string word1, string word2) {
        vector<vector<int>> memo(word1.size() + 1, vector<int>(word2.size() + 1, -1));
        return editDistance(word1, word2, memo, word1.size(), word2.size());
    }
};
// @lc code=end

