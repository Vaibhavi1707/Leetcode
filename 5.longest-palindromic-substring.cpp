/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
class Solution {
public:
    int dp(string s, vector<int>& memo, int l, int r) {
        if (l > r) return "";
        if (l < 0 || r > s.length() - 1) return ;

        if (memo[l * s.length() + r] != 0) return memo[l * s.length() + r];
        
        if (s[l] == s[r]) {
            return 2 + dp(s, memo, l - 1, r + 1);
        } 
        else if (s[l - 1] == s[r]) {
            return 1 + dp(s, memo, l - 1, r + 1);
        }
        else if (s[l] == s[r + 1]) {
            return 1 + dp(s, memo, l)
        }
        else {
            return dp(s, memo, l + 1, r - 1);
        }

    }

    string longestPalindrome(string s) {
        vector<int> memo(s.length() * s.length(), 0);
        string res = dp(s, memo, (s.length - 1) / 2, (s.length - 1) / 2);
        cout << res;
        int max_size = 0;
        string max_str = "";
        for (string s: memo) {
            if (s.length() > max_size and s != "$") {
                max_str = s;
                max_size = s.length();
            }
        }
        return max_str;
    }
};
// @lc code=end

