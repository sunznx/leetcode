// CreateTime: 2021-01-06 00:56:10
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int row = A.size();
        int col = A[0].size();

        vector<vector<int>> dp(row+1, vector<int>(col+2, INT_MAX));

        for (int i = 0; i < dp[0].size(); i++) {
            dp[0][i] = 0;
        }

        for (int i = 1; i <= row; i++) {
            for (int j = 1; j <= col; j++) {
                dp[i][j] = min({dp[i-1][j], dp[i-1][j-1], dp[i-1][j+1]}) + A[i-1][j-1];
            }
        }

        int ans = INT_MAX;
        for (int i = 0; i < dp[row].size(); i++){
            ans = min(ans, dp[row][i]);
        }
        return ans;
    }
};