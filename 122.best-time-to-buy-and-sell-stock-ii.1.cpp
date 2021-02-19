// CreateTime: 2021-02-19 14:14:47
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        vector<vector<int>> f(len, vector<int>(2));

        // f[i][0] 表示持有股票的收益
        // f[i][1] 表示没有股票的收益

        f[0][0] = -prices[0];
        f[0][1] = 0;

        for (int i = 1; i < len; i++) {
            f[i][0] = max(f[i-1][0], f[i-1][1]-prices[i]);
            f[i][1] = max(f[i-1][1], f[i-1][0]+prices[i]);
        }

        return f[len-1][1];
    }
};
