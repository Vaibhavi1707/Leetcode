/*
 * @lc app=leetcode id=327 lang=cpp
 *
 * [327] Count of Range Sum
 */

// @lc code=start

vector<long long> prefixSum(vector<int> arr) {
    vector<long long> preSum(arr.size() + 1, 0);
    for (int i = 0; i < arr.size(); i ++) {
        preSum[i + 1] = preSum[i] + arr[i];
    }
    return preSum;
}

class Solution {
public:
    int inversion(vector<long long>& nums, int l, int m, int r, int lower, int upper) {
        int res = 0;
        for (int i = m + 1; i <= r; i ++) {
                res += upper_bound(nums.begin() + l, nums.begin() + m + 1, nums[i] - lower) - 
                lower_bound(nums.begin() + l, nums.begin() + m + 1, nums[i] - upper);
            }
        return res;
    }

    int merge(vector<long long>& nums, int l, int m, int r, int lower, int upper) {
        int res = inversion(nums, l, m, r, lower, upper);
        if (nums[m] <= nums[m + 1]) return res;

        vector<long long> sorted_nums(r -l + 1, 0);
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

    int mergesort_and_count(vector<long long>& nums, int l, int r, int lower, int upper) {
        if (l >= r) {
            return 0;
        } 

        int m = (r + l) / 2;
        int left_count = mergesort_and_count(nums, l, m, lower, upper);
        int right_count = mergesort_and_count(nums, m + 1, r, lower, upper);
        int merged_count = merge(nums, l, m, r, lower, upper);
        return left_count + right_count + merged_count;
    }

    int countRangeSum(vector<int>& nums, int lower, int upper) {
        vector<long long> preSum = prefixSum(nums);
        int res = mergesort_and_count(preSum, 0, nums.size(), lower, upper);
        return res;
    }
};
// @lc code=end

