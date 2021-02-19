// CreateTime: 2021-02-19 16:55:54
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.size() == 0 || k == 0) {
            return 0;
        }

        int len = prices.size();
        vector<vector<vector<int>>> f(len, vector<vector<int>>(k, vector<int>(2)));

        // f[i][k][0] 表示持有股票 k
        // f[i][k][1] 表示没持有股票 k

        for (int j = 0; j < k; j++) {
            f[0][j][0] = -prices[0];
        }
        for (int i = 1; i < len; i++) {
            auto x = prices[i];

            f[i][0][0] = max(f[i-1][0][0], -x);
            f[i][0][1] = max(f[i-1][0][1], f[i-1][0][0]+x);

            for (int j = 1; j < k; j++) {
                f[i][j][0] = max(f[i-1][j][0], f[i-1][j-1][1]-x);
                f[i][j][1] = max(f[i-1][j][1], f[i-1][j][0]+x);
            }
        }

        auto ans = 0;
        for (int j = 0; j < k; j++) {
            ans = max({ans, f[len-1][j][0], f[len-1][j][1]});
        }
        return ans;
    }
};
