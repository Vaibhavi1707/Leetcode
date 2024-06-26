/*
 * @lc app=leetcode id=274 lang=cpp
 *
 * [274] H-Index
 */

// @lc code=start
class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.rbegin(), citations.rend());

        for (int i = 0 ; i < citations.size() ; i++) {
            if (i + 1 > citations[i]) {
                return i;
            }
        }

        return citations.size();
    }
};
// @lc code=end

