/*
 * @lc app=leetcode id=1094 lang=cpp
 *
 * [1094] Car Pooling
 */

// @lc code=start
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(), trips.end(), [](vector<int> trip1, vector<int> trip2){ return trip1[1] < trip2[1];});

        int total_pass = trips[0][0];
        int start = trips[0][1];
        int end = trips[0][2];
        for (int i = 1; i < trips.size(); i++) {
            if (end <= trips[i][1]) {
                if (total_pass > capacity) return false;
                start = trips[i][1];
                end = trips[i][2];
                total_pass = trips[i][0];
                continue;
            }
            end = max(end, trips[i][2]);
            if (end < trips[i][2]) {
                
            }
            total_pass += trips[i][0];
            if (total_pass > capacity) return false;
        }

        return true;
    }
};
// @lc code=end

