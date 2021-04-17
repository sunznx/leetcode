// CreateTime: 2021-04-18 00:42:24
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        int len = nums.size();

        sort(nums.begin(), nums.end());
        for (int i = 0; i < (1<<len); i++) {
            bool ok = true;
            vector<int> sub;
            for (int j = 0; j < len; j++) {
                if ((i & (1<<j)) == 0) {
                    continue;
                }

                if (j > 0 && nums[j] == nums[j-1] && (i&(1<<(j-1))) == 0) {
                    ok = false;
                    break;
                }

                sub.push_back(nums[j]);
            }

            if (ok) {
                res.push_back(sub);
            }
        }
        return res;
    }
};
