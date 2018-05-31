class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int sum = 0;
        for (int i = 1; i < n; i++) {
            int num = prices[i] - prices[i-1];
            if (num > 0) {
                sum += num;
            }
        }
        return sum;
    }
};
