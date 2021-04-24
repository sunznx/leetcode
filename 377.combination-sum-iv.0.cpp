// CreateTime: 2021-04-24 12:13:07
class Solution {
public:
    typedef unsigned long long ULL;

    int combinationSum4(vector<int>& nums, int target) {
        int len = target;
        vector<vector<ULL>> f(target+1, vector<ULL>(target+1));

        f[0][0] = 1;
        for (int i = 1; i <= len; i++) {
            for (int j = 0; j <= target; j++) {
                for (auto &x: nums) {
                    if (j >= x) {
                        f[i][j] += f[i-1][j-x];
                    }
                }
            }
        }

        int ans = 0;
        for (int i = 1; i <= len; i++) {
            ans += f[i][target];
        }
        return ans;
    }
};
