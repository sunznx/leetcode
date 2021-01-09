// CreateTime: 2021-01-09 16:37:42
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) {
            return 0;
        }

        // dp[x][0] 表示 x 状态下持有股票
        // dp[x][1] 表示 x 状态下没有股票
        vector<vector<int>> dp(prices.size(), vector<int>(2, 0));

        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        for (int i = 1; i < prices.size(); i++) {
            auto x = prices[i];

            dp[i][0] = max(dp[i-1][0], dp[i-1][1]-x);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0]+x);
        }

        return max(dp[prices.size()-1][0], dp[prices.size()-1][1]);
    }
};
