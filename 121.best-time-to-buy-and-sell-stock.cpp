// CreateTime: 2019-12-15 10:03:40
class Solution {
public:

    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int minv = 0x7fffffff;

        for (int i = 0; i < prices.size(); i++) {
            auto x = prices[i];
            ans = max(ans, x - minv);
            minv = min(minv, x);
        }

        return ans;
    }
};
