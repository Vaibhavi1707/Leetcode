/*
 * @lc app=leetcode id=350 lang=cpp
 *
 * [350] Intersection of Two Arrays II
 */

// @lc code=start
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> freq1, freq2;

        for (int i = 0; i < nums1.size(); i++) freq1[nums1[i]] ++;
        for (int i = 0; i < nums2.size(); i++) freq2[nums2[i]] ++;

        vector<int> res;
        for(auto item: freq1) {
            int elem = item.first;
            int freq = item.second;
            if (freq2.find(elem) != freq2.end() && freq2[elem] > 0) {
                int final_freq = min(freq2[elem], freq);
                for (int i = 0; i < final_freq; i ++) res.push_back(elem);
            }
        }

        return res;
    }
};
// @lc code=end

