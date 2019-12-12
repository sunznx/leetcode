// CreateTime: 2019-12-12 21:42:15
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

        return max(rob(nums, 0, len-2), rob(nums, 1, len-1));
    }

    int rob(vector<int> &nums, int l, int r) {
        int len = r-l+1;
        if (len == 0) {
            return 0;
        }
        if (len == 1) {
            return nums[l];
        }

        vector<int> dp(len);
        dp[0] = nums[l];
        dp[1] = max(nums[l], nums[l+1]);
        for (int i = 2; i < len; i++) {
            dp[i] = max(dp[i-1], dp[i-2]+nums[l+i]);
        }
        return dp[len-1];
    }
};
