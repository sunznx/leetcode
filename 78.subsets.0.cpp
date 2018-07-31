class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;

        int len = nums.size();
        for (int i = 0; i < (1<<len); i++) {
            vector<int> v;
            for (int j = 0; j < len; j++) {
                if ((i & (1 << j))) {
                    v.push_back(nums[j]);
                }
            }
            res.push_back(v);
        }
        return res;
    }
};
