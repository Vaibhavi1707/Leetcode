/*
 * @lc app=leetcode id=349 lang=cpp
 *
 * [349] Intersection of Two Arrays
 */

// @lc code=start
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> set1, set2;

        for (int i = 0; i < nums1.size(); i++) {
            set1.insert(nums1[i]);
        }

        for (int i = 0; i < nums2.size(); i++) {
            set2.insert(nums2[i]);
        }

        vector<int> res;
        for (int num: set1) {
            if (set2.find(num) != set2.end()) {
                res.push_back(num);
            }
        }

        return res;
    }
};
// @lc code=end

