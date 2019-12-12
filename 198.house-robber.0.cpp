// CreateTime: 2019-12-12 14:12:40
class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) {
            return 0;
        }

        vector<int> dp(len+1);

        dp[1] = nums[0];
        for (int i = 1; i < len; i++) {
            dp[i+1] = max(dp[i], nums[i] + dp[i-1]);
        }

        return dp[len];
    }
};
