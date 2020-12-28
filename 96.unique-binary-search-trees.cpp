// CreateTime: 2020-01-16 23:33:04
class Solution {
  public:
    int numTrees(int n) {
        vector<int> dp(n+1);
        dp[0] = 1;
        dp[1] = 1;
        return f(dp, n);
    }

    int f(vector<int> &dp, int n) {
        if (dp[n]) {
            return dp[n];
        }

        int ans = 0;
        for (int i = 0; i <= n-1; i++) {
            ans += f(dp, i) * f(dp, n-1-i);
        }
        return dp[n] = ans;
    }
};
