// CreateTime: 2021-02-19 17:01:52
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if (len == 0) {
            return 0;
        }

        vector<vector<int>> f(len, vector<int>(3));

        // f[i][0]  表示买入了股票
        // f[i][1]  表示卖出了股票
        // f[i][2]  表示处于冷静期

        f[0][0] = -prices[0];
        for (int i = 1; i < len; i++) {
            auto x = prices[i];

            f[i][0] = max(f[i-1][0], f[i-1][2]-x);
            f[i][1] = f[i-1][0]+x;
            f[i][2] = max(f[i-1][2], f[i-1][1]);
        }

        return max({f[len-1][0], f[len-1][1], f[len-1][2]});
    }
};
