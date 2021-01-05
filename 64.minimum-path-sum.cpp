// CreateTime: 2021-01-05 11:43:41
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        if (row == 0) {
            return 0;
        }

        int col = grid[0].size();

        vector<vector<int>> dp(row, vector<int>(col, INT_MAX));

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                auto &x = grid[i][j];

                if (i == 0 && j == 0) {
                    dp[i][j] = x;
                } else if (i == 0) {
                    dp[i][j] = dp[i][j-1] + x;
                } else if (j == 0) {
                    dp[i][j] = dp[i-1][j] + x;
                } else {
                    dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + x;
                }
            }
        }

        return dp[row-1][col-1];
    }
};
