// CreateTime: 2021-04-15 01:00:58
class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) {
            return 0;
        }
        if (len == 1) {
            return nums[0];
        }

        vector<vector<int>> dp(len, vector<int>(2));

        // dp[x][0] 表示选择 x 的时候，最大是多少
        // dp[x][1] 表示不选择 x 的时候，最大是多少
        dp[0][0] = nums[0];
        dp[0][1] = 0;
        dp[1][0] = nums[1];
        dp[1][1] = nums[0];

        for (int i = 2; i < len; i++) {
            auto x = nums[i];
            dp[i][0] = x + max({dp[i-2][0], dp[i-2][1], dp[i-1][1]});
            dp[i][1] = max({dp[i-2][0], dp[i-2][1], dp[i-1][0], dp[i-1][1]});
        }

        return max(dp[len-1][0], dp[len-1][1]);
    }
};
