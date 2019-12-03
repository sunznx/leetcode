class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        int len = nums.size();
        for (int i = 0; i < (1<<len); i++) {
            vector<int> v;
            for (int j = 0; j < len; j++) {
                if (((1 << j) & i)) {
                    v.push_back(nums[j]);
                }
            }
            res.push_back(v);
        }

        sort(res.begin(), res.end());
        res.resize(unique(res.begin(), res.end()) - res.begin());

        return res;
    }
};
