/*
 * @lc app=leetcode id=324 lang=cpp
 *
 * [324] Wiggle Sort II
 */

// @lc code=start
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int mid = nums.size() % 2 == 1 ? (nums.size() - 1) / 2 : ((nums.size()) / 2) - 1;
        vector<int> res(nums.size(), 0);
        int k = 0;
        for (int i = mid; i >= 0; i --) {
            res[k] = nums[i];
            k += 2;
        }

        int p = 1;
        for (int j = nums.size() - 1; j > mid; j --) {
            res[p] = nums[j];
            p += 2;
        }

        for (int i = 0; i < nums.size(); i ++) {
            nums[i] = res[i];
        }
    }
};
// @lc code=end

