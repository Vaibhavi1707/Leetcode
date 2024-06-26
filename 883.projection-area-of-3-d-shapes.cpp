/*
 * @lc app=leetcode id=883 lang=cpp
 *
 * [883] Projection Area of 3D Shapes
 */

// @lc code=start

class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int area = 0;
        int nonzero = 0;
        for (int i = 0; i < grid.size(); i++) {
            int max_col = 0;
            int max_row = 0;
            for (int j = 0; j < grid.size(); j++) {
                max_col = max(max_col, grid[j][i]);
                max_row = max(max_row, grid[i][j]);
                nonzero += int(grid[i][j] != 0);
            }
            area += max_col + max_row;
        }
        return area + nonzero;
    }
};
// @lc code=end

