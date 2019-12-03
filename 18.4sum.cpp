class Solution {
public:
    int bin_search(int from, vector<int> &nums, int v) {
        int len = nums.size();
        if (from >= len) {
            return -1;
        }

        int l = from;
        int r = len-1;

        while (r >= l) {
            int mid = (l+r) / 2;
            int check_res = v - nums[mid];
            if (check_res == 0) {
                return mid;
            } else if (check_res > 0) {
                l = mid+1;
            } else {
                r = mid-1;
            }
        }

        return -1;
    }

    void dfs(int n, int from, int step, vector<int>& nums, vector<int>& v, vector<int> tmp, vector<vector<int>>& res, int target) {
        if (n == step+1) {
            tmp[3] = target-(tmp[0] + tmp[1] + tmp[2]);
            auto index = bin_search(from, nums, tmp[3]);
            if (index == -1) {
                return;
            }
            res.push_back(tmp);
            return;
        }

        for (int i = from; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i-1] && !v[i-1]) {
                continue;
            }

            if (!v[i]) {
                tmp[n-1] = nums[i];
                v[i] = 1;
                dfs(n+1, i+1, step, nums, v, tmp, res, target);
                v[i] = 0;
            }
        }
    }

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int len = nums.size();

        if (len >= 4) {
            sort(nums.begin(), nums.end());
            vector<int> v(len+1, 0);
            vector<int> tmp(4, 0);
            dfs(1, 0, 3, nums, v, tmp, res, target);
        }

        return res;
    }
};
