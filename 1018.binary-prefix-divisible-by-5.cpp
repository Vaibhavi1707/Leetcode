/*
 * @lc app=leetcode id=1018 lang=cpp
 *
 * [1018] Binary Prefix Divisible By 5
 */

// @lc code=start
class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> res;
        int curr_binary = 0;
        for (int i = 0; i < nums.size(); i ++) {
            curr_binary = (2 * curr_binary + nums[i]) % 5;
            res.push_back(curr_binary == 0);
        }
        return res;
    }
};
// @lc code=end

