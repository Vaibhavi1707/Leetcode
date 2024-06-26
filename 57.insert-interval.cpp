/*
 * @lc app=leetcode id=57 lang=cpp
 *
 * [57] Insert Interval
 */

// @lc code=start

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), [](const vector<int>&a, vector<int>&b){
        return a[0] < b[0]; 
    });
    
    int start = intervals[0][0];
    int end = intervals[0][1];
    vector<vector<int>> res;  
    for (int i = 1; i < intervals.size(); i ++) {
        if (end < intervals[i][0]) {
            res.push_back({start, end});
            start = intervals[i][0];
            end = intervals[i][1];
            continue;
        }
        end = max(end, intervals[i][1]);
    }
    res.push_back({start, end});
    return res;
}

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        return merge(intervals);
    }
};
// @lc code=end

