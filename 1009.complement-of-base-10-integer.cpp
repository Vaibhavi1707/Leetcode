/*
 * @lc app=leetcode id=1009 lang=cpp
 *
 * [1009] Complement of Base 10 Integer
 */

// @lc code=start
class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0) return 1;
        string res = "";
        while (n > 0) {
            int rem = !(n % 2);
            // cout << n % 2 << " ";
            res = to_string(rem) + res;
            n = n / 2;
        }
        // cout << endl << res << endl;
        return stoi(res, nullptr, 2);
    }
};
// @lc code=end

