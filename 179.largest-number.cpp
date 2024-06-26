/*
 * @lc app=leetcode id=179 lang=cpp
 *
 * [179] Largest Number
 */

// @lc code=start
class Solution {
public:
    static bool compare_str(const string s1, const string s2) {
        return s1 + s2 > s2 + s1;
    }

    string removeLeadingZeros(string s) {
        int i = 0;
        while (i < s.length() && s[i] == '0') {
            i ++;
        }

        if (i == s.length()) {
            return "0";
        }

        return s.substr(i);
    }

    string largestNumber(vector<int>& nums) {
        vector<string> str_nums;
        for (int num: nums) {
            str_nums.push_back(to_string(num));
        }

        sort(str_nums.begin(), str_nums.end(), compare_str);

        string ans = "";
        for (int i = 0; i < str_nums.size(); i++) {
            ans += str_nums[i];
        }

        return removeLeadingZeros(ans);
    }
};
// @lc code=end

