/*
 * @lc app=leetcode id=164 lang=cpp
 *
 * [164] Maximum Gap
 */

// @lc code=start
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int max_diff = 0;
        for (int i = 1; i < nums.size(); i ++) {
            max_diff = max(max_diff, nums[i] - nums[i - 1]);
        }

        return max_diff;
    }
};
// @lc code=end

