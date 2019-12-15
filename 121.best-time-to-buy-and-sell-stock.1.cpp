// CreateTime: 2019-12-15 10:03:40
class Solution {
public:

    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        int ans = 0;
        int minv = 0x3fffffff;
        for (int i = 0; i < len; i++) {
            ans = max(ans, prices[i] - minv);
            minv = min(minv, prices[i]);            
        }
        return ans;
    }
};
