/*
 * @lc app=leetcode id=315 lang=cpp
 *
 * [315] Count of Smaller Numbers After Self
 */

// @lc code=start

class Solution {
public:
    void countafter(vector<tuple<int, int, int>>& nums, int start, int mid, int end) {
        // for (int i = 0; i < nums.size(); i++) {
        //     cout << get<0>(nums[i]) << " " << get<1>(nums[i]) << " " << get<2>(nums[i]) << endl;
        // }
        int cr = end;
        for (int i = mid; i >= start; i --) {
            while (cr >= mid + 1) {
                if (get<0>(nums[i]) > get<0>(nums[cr])) {
                    get<2>(nums[i]) += cr - mid;
                    break;
                }
                cr --;
            }
        }
        // for (int i = 0; i < nums.size(); i++) {
        //     cout << get<0>(nums[i]) << " " << get<1>(nums[i]) << " " << get<2>(nums[i]) << endl;
        // }
    }


    void merge(vector<tuple<int, int, int>>& nums, int start, int mid, int end) {
        countafter(nums, start, mid, end);
        if (nums[mid] < nums[mid + 1]) {
            return;
        }

        vector<tuple<int, int, int>> sorted_nums(end - start + 1, {0, 0, 0});
        int i = start, k = 0, j = mid + 1;
        while (i <= mid && j <= end) {
            if (get<0>(nums[i]) <= get<0>(nums[j])) {
                sorted_nums[k ++] = nums[i ++];
            }
            else {
                sorted_nums[k ++] = nums[j ++];
            }
        }
        while (i <= mid) {
            sorted_nums[k ++] = nums[i ++];
        }
        while (j <= end) {
            sorted_nums[k ++] = nums[j ++];
        }       
        int p = 0;
        for(int i = start; i <= end; i ++) {
            nums[i] = sorted_nums[p ++];
        }
    }

    void merge_count(vector<tuple<int, int, int>>& nums, int start, int end) {
        if (start >= end) { return; }
        int mid = (start + end) / 2;

        merge_count(nums, start, mid);
        merge_count(nums, mid + 1, end);
        merge(nums, start, mid, end);
    }

    vector<int> countSmaller(vector<int>& nums) {
        // cout << nums.size() << endl;
        vector<tuple<int, int, int>> num_ind_pairs;
        for (int i = 0; i < nums.size(); i++) {
            num_ind_pairs.push_back({nums[i], i, 0});
        }
        vector<int> res(nums.size(), 0);
        merge_count(num_ind_pairs, 0, nums.size() - 1);
        for (int i = 0; i < num_ind_pairs.size(); i ++) {
            res[get<1>(num_ind_pairs[i])] = get<2>(num_ind_pairs[i]);
        }
        return res;
    }
};
// @lc code=end

