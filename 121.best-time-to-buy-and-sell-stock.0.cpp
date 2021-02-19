// CreateTime: 2021-02-19 14:09:57
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;

        int minVal = prices[0];
        for (auto &x: prices) {
            ans = max(ans, x-minVal);
            minVal = min(minVal, x);
        }

        return ans;
    }
};
