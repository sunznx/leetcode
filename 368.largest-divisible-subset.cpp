// CreateTime: 2021-04-23 10:09:37
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int maxVal = 0;
        int maxIdx = 0;
        vector<int> dp(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++) {
            dp[i] = 1;
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0) {
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }

            if (dp[i] > maxVal) {
                maxVal = dp[i];
                maxIdx = i;
            }
        }

        int i = maxIdx;
        vector<int> ans = {nums[i]};
        for (int j = nums.size()-1; j >= 0; j--) {
            if (nums[i] % nums[j] == 0 && dp[j]+1 == dp[i]) {
                i = j;
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};
