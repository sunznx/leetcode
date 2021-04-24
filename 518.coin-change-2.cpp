// CreateTime: 2021-04-24 10:12:53
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1, 0);

        dp[0] = 1;
        for (int i = 0; i < coins.size(); i++) {
            auto x = coins[i];
            for (int j = x; j <= amount; j++) {
                dp[j] += dp[j-x];
            }
        }
        return dp[amount];
    }
};
