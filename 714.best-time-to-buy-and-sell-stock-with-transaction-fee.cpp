// CreateTime: 2021-02-19 17:11:34
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int len = prices.size();
        if (len == 0) {
            return 0;
        }

        // f[i][0] 表示持有股票
        // f[i][1] 表示没有股票

        vector<vector<int>> f(len, vector<int>(2));
        f[0][0] = -prices[0];
        for (int i = 1; i < len; i++) {
            auto x = prices[i];

            f[i][0] = max(f[i-1][0], f[i-1][1]-x);
            f[i][1] = max(f[i-1][1], f[i-1][0]+x-fee);
        }

        return max(f[len-1][0], f[len-1][1]);
    }
};
