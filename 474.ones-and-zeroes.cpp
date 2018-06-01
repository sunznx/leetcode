class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int len = strs.size();

        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        for (int i = 0; i < len; i++) {
            int zero = 0;
            int one  = 0;

            for (int j = 0; j < strs[i].size(); j++) {
                if (strs[i][j] == '0') {
                    zero++;
                } else if (strs[i][j] == '1') {
                    one++;
                }
            }

            for (int x = m; x >= zero; x--) {
                for (int y = n; y >= one; y--) {
                    dp[x][y] = max(dp[x-zero][y-one]+1, dp[x][y]);
                }
            }
        }
        
        return dp[m][n];
    }
};
