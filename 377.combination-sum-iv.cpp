// CreateTime: 2021-04-24 00:14:39
class Solution {
public:

    typedef unsigned long long ULL;

    int combinationSum4(vector<int>& nums, int target) {
        vector<ULL> dp(target+1, 0);

        dp[0] = 1;
        for (int i = 0; i <= target; i++) {
            for (int j = 0; j < nums.size(); j++) {
                auto x = nums[j];
                if (i >= x) {
                    dp[i] += dp[i-x];
                }
            }
        }
        return dp[target];
    }
};
