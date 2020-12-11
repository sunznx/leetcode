// CreateTime: 2019-11-22 14:00:58
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, amount+1);

        dp[0] = 0;
        for (int i = 0; i < coins.size(); i++) {
            auto x = coins[i];
            for (int j = x; j <= amount; j++) {
                dp[j] = min(dp[j], dp[j-x] + 1);
            }
        }

        if (dp[amount] == amount+1) {
            return -1;
        }
        return dp[amount];
    }
};
