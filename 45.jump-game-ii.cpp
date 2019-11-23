// CreateTime: 2019-11-23 01:14:42
class Solution {
public:
    int jump(vector<int>& nums) {
        int W = nums.size()-1;

        vector<int> dp(W+1, W+1);
        vector<int> forward(W+1, 0);

        dp[0] = 0;
        for (int i = 0; i < nums.size()-1; i++) {
            for (int j = forward[i]; j <= i+nums[i] && j <= W; j++) {
                dp[j] = min(dp[j], dp[i] + 1);
            }
            forward[i+1] = min(i+nums[i], W);
        }
        return dp[W];
    }
};

