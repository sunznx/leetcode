class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();

        vector<int> dp(len+1, 0);

        int maxValue;

        maxValue = nums[0];
        dp[0] = nums[0];

        for (int i = 1; i < len; i++) {
            dp[i] = max(nums[i], dp[i-1] + nums[i]);
            maxValue = max(dp[i], maxValue);
        }

        return maxValue;
    }
};
