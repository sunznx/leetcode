class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> arr = nums;
        vector<bool> v(nums.size(), false);
        dfs(nums, arr, v, nums.size(), 0);
        return res;
    }

    void dfs(vector<int>& nums, vector<int>& arr, vector<bool>& v, int n, int step) {
        if (n == step) {
            res.push_back(arr);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (!v[i]) {
                v[i] = true;
                arr[step] = nums[i];
                dfs(nums, arr, v, n, step+1);
                v[i] = false;
            }
        }
    }
};
