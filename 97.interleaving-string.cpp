/*
 * @lc app=leetcode id=97 lang=cpp
 *
 * [97] Interleaving String
 */

// @lc code=start
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s3.length() != s1.length() + s2.length()) {
            return false;
        }

        int p = 0, p1 = 0, p2 = 0;
        bool f1 = false, f2 = false;
        while (p < s3.length()) {
            while (p < s3.length() && p1 < s1.length() && s1[p1] == s3[p]) {
                p ++;
                p1 ++;
                f1 = true;
            }
            while (p < s3.length() && p2 < s2.length() && s2[p2] == s3[p]) {
                p ++;
                p2 ++;
                f2 = true;
            }
            if (!f1 && !f2) {
                return false;
            }
            p ++;
            f1 = false;
            f2 = false;
        }

        return true;
    }
};
// @lc code=end

