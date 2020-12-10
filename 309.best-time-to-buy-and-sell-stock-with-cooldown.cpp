// CreateTime: 2020-12-10 04:23:51
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if (len == 0) {
            return 0;
        }

        vector<int> hold(len);     // 在当前状态下持有股票
        vector<int> sold(len);     // 在当前状态下没有持有股票
        vector<int> cooldown(len); // 当前状态是 cooldown 状态

        hold[0] = -prices[0];
        for (int i = 1; i < len; i++) {
            hold[i] = max(hold[i-1], cooldown[i-1]-prices[i]);
            sold[i] = hold[i-1] + prices[i];
            cooldown[i] = max(cooldown[i-1], sold[i-1]);
        }

        return max(hold[len-1], max(sold[len-1], cooldown[len-1]));
    }
};
