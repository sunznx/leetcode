class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();

        if (len == 0) {
            return 0;
        } else if (len == 1) {
            return 0;
        }

        vector<int> dp(len+1, 0);
        int maxValue = 0;

        int Buy = prices[0];

        for (int i = 1; i < len; i++) {
            Buy = min(Buy, prices[i]);
            maxValue = max(maxValue, prices[i] - Buy);
        }

        return maxValue;
    }
};
