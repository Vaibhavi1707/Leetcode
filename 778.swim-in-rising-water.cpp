/*
 * @lc app=leetcode id=778 lang=cpp
 *
 * [778] Swim in Rising Water
 */

// @lc code=start
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int t = 0;
        int n = grid.size();
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < n; j ++) {
                int up = i > 0 ? grid[i - 1][j]:-1;
                int down = i < n - 1 ? grid[i + 1][j]:-1;
                int left = j > 0 ? grid[i][j - 1] : -1;
                int right = j < n - 1 ? grid[i][j + 1] : -1;

                vector<int> can_go;
                if (up != -1) {
                    can_go.push_back(up);
                }
                if (down != -1) {
                    can_go.push_back(down);
                }
                if (left != -1) {
                    can_go.push_back(left);
                }
                if (right != -1) {
                    can_go.push_back(right);
                }

                int to_go = *min_element(can_go.begin(), can_go.end());
                t += to_go;
            }
        }
    }
};
// @lc code=end

