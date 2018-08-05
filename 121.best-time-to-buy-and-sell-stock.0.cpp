class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if (len <= 1) {
            return 0;
        }
        
        int res = 0;
        int cur = 0;
        int minn = prices[0];
        for (int i = 1; i < len; i++) {
            minn = min(minn, prices[i]);
            cur = prices[i] - minn;
            res = max(res, cur);
        }
        
        return res;
    }
};
