// CreateTime: 2021-01-09 15:59:26
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // dp[x][0][0] 表示 x 状态下持有股票 0
        // dp[x][0][1] 表示 x 状态下卖出股票 0

        // dp[x][1][0] 表示 x 状态下持有股票 0 和 1
        // dp[x][1][1] 表示 x 状态下卖出股票 0 和 1
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(2, vector<int>(2, 0)));

        dp[0][0][0] = -prices[0];
        dp[0][1][0] = -prices[0];
        for (int i = 1; i < prices.size(); i++) {
            auto x = prices[i];

            dp[i][0][0] = max(dp[i-1][0][0], -x);
            dp[i][0][1] = max(dp[i-1][0][1], dp[i-1][0][0]+x);

            dp[i][1][0] = max(dp[i-1][1][0], dp[i-1][0][1]-x);
            dp[i][1][1] = max(dp[i-1][1][1], dp[i-1][1][0]+x);
        }

        return max(dp[prices.size()-1][0][1], dp[prices.size()-1][1][1]);
    }
};
