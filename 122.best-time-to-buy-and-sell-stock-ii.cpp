// CreateTime: 2019-12-15 10:12:54
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if (len == 0) {
            return 0;
        }

        vector<int> dp(len);
        
        for (int i = 1; i < len; i++) {
            if (prices[i] > prices[i-1]) {
                dp[i] = dp[i-1] + prices[i]-prices[i-1];
            } else {
                dp[i] = dp[i-1];
            }
        }
        return dp[len-1];
    }
};
