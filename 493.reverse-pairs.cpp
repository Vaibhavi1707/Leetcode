/*
 * @lc app=leetcode id=493 lang=cpp
 *
 * [493] Reverse Pairs
 */

// @lc code=start
class Solution {
public:
    int inversion(vector<long long>& nums, int l, int m, int r) {
        int res = 0;
        int cl = l;
        for (int i = m + 1; i <= r; i ++) {
            while (cl <= m) {
                if (nums[cl] > 2 * nums[i]) {
                    res += (m - cl + 1);
                    break;
                }
                cl ++;
            }
        }
        return res;
    }

    int merge(vector<long long>& nums, int l, int m, int r) {
        int res = inversion(nums, l, m, r);
        if (nums[m] <= nums[m + 1]) return res;

        vector<long long> sorted_nums(r -l +, 0);
        int i = l;
        int k = 0;
        int j = m + 1;
        while (i <= m && j <= r) {
            if (nums[i] <= nums[j]) {
                sorted_nums[k++] = nums[i++];
            }
            else {
                sorted_nums[k++] = nums[j++];
            }
        }
        while (i <= m) {
            sorted_nums[k++] = nums[i++];
        }

        while (j <= r) {
            sorted_nums[k++] = nums[j++];
        }
        int s = 0;
        for (int i = l; i <= r; i++) {
            nums[i] = sorted_nums[s ++];
        }
        return res;
    }

    int mergesort_and_count(vector<long long>& nums, int l, int r) {
        if (l >= r) {
            return 0;
        }

        int m = (r + l) / 2;
        int left_count = mergesort_and_count(nums, l, m);
        int right_count = mergesort_and_count(nums, m + 1, r);
        int merged_count = merge(nums, l, m, r);
        return left_count + right_count + merged_count;
    }

    int reversePairs(vector<int>& nums) {
        vector<long long> lnums;
        for (int i = 0; i < nums.size(); i ++) {
            lnums.push_back(nums[i]);
        }
        int res = mergesort_and_count(lnums, 0, nums.size() - 1);
        return res;
    }
};
// @lc code=end

