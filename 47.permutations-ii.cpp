// CreateTime: 2019-12-13 08:33:14
class Solution {
public:
    vector<vector<int>> res;
    vector<int> arr;
    vector<bool> v;

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        v.resize(nums.size());
        arr.resize(nums.size());
        sort(nums.begin(), nums.end());
        dfs(nums);
        return res;
    }

    void dfs(vector<int>& nums, int step = 0) {
        int len = nums.size();
        if (step == len) {
            res.push_back(arr);
            return;
        }

        for (int i = 0; i < len; i++) {
            if (i > 0 && nums[i] == nums[i-1] && !v[i-1]) {
                continue;
            }

            if (!v[i]) {
                v[i] = true;
                arr[step] = nums[i];
                dfs(nums, step+1);
                v[i] = false;
            }
        }
    }
};
