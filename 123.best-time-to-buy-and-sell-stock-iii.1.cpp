// CreateTime: 2021-02-19 15:12:27
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        vector<vector<vector<int>>> f(len, vector<vector<int>>(2, vector<int>(2)));

        // f[i][0][0] 表示持有股票 0
        // f[i][0][1] 表示没持有股票 0

        // f[i][1][0] 表示持有股票 1
        // f[i][1][1] 表示没持有股票 1

        f[0][0][0] = -prices[0];
        f[0][1][0] = -prices[0];
        for (int i = 1; i < len; i++) {
            auto x = prices[i];

            f[i][0][0] = max(f[i-1][0][0], -x);
            f[i][0][1] = max(f[i-1][0][1], f[i-1][0][0]+x);

            f[i][1][0] = max(f[i-1][1][0], f[i-1][0][1]-x);
            f[i][1][1] = max(f[i-1][1][1], f[i-1][1][0]+x);
        }

        return max({f[len-1][0][0], f[len-1][0][1], f[len-1][1][0], f[len-1][1][1]});
    }
};
