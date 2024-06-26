/*
 * @lc app=leetcode id=219 lang=cpp
 *
 * [219] Contains Duplicate II
 */

// @lc code=start
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        vector<pair<int, int>> num_loc;
        for (int i = 0; i < nums.size(); i++) {
            num_loc.push_back(make_pair(nums[i], i));
        }

        sort(num_loc.begin(), num_loc.end());

        for (int i = 0; i < num_loc.size() - 1; i++) {
            if (num_loc[i].first == num_loc[i + 1].first) {
                if (abs(num_loc[i].second - num_loc[i + 1].second) <= k) {
                    return true;
                }
            }
        }

        return false;
    }   
};
// @lc code=end

