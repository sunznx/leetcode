// CreateTime: 2021-01-09 17:45:02
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.size() == 0 || k == 0) {
            return 0;
        }

        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(k, vector<int>(2, 0)));

        // dp[i][j][0]  表示在 i 状态下，持有 j 股票
        // dp[i][j][0]  表示在 i 状态下，卖出 j 股票

        for (int i = 0; i < k; i++) {
            dp[0][i][0] = -prices[0];
        }

        for (int i = 1; i < prices.size(); i++) {
            auto x = prices[i];

            dp[i][0][0] = max(dp[i-1][0][0], -x);
            dp[i][0][1] = max(dp[i-1][0][1], dp[i-1][0][0]+x);
            for (int j = 1; j < k; j++) {
                dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j-1][1]-x);
                dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j][0]+x);
            }
        }

        int ans = 0;
        for (int j = 0; j < k; j++) {
            ans = max(ans, dp[prices.size()-1][j][1]);
        }
        return ans;
    }
};
