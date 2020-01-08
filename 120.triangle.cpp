class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int raw = triangle.size();
        int res;
        vector<vector<int>> dp(raw+1, vector<int>(raw+1, 0));
        for (int i = 0; i < raw; i++) {
            for (int j = 0; j < triangle[i].size(); j++) {
                if (j == 0 && i == 0) {
                    dp[i][j] = triangle[i][j];
                } else if (i == 0) {
                    dp[i][j] = triangle[i][j] + dp[i][j-1];
                } else if (j == 0) {
                    dp[i][j] = triangle[i][j] + dp[i-1][j];
                } else {
                    if (j < triangle[i-1].size()) {
                        dp[i][j] = min(dp[i-1][j-1] + triangle[i][j], dp[i-1][j] + triangle[i][j]);
                    } else {
                        dp[i][j] = dp[i-1][j-1] + triangle[i][j];
                    }
                }

                if (i == raw-1 && j == 0) {
                    res = dp[i][j];
                } else if (i == raw-1) {
                    res = min(res, dp[i][j]);
                }
            }
        }

        return res;
    }
};
