// CreateTime: 2019-12-03 19:21:53
class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.size();
        int len2 = word2.size();

        vector<vector<int>> dp(len1+1, vector<int>(len2+1, max(len1, len2)));

        for (int i = 0; i < len1; i++) {
            dp[i][0] = i;
        }
        for (int i = 0; i < len2; i++) {
            dp[0][i] = i;
        }

        for (int i = 0; i < len1; i++) {
            for (int j = 0; j < len2; j++) {
                auto &x = dp[i+1][j+1];
                if (word1[i] == word2[j]) {
                    x = min(x, dp[i][j]);
                } else {
                    x = min(x, dp[i][j]+1);
                    x = min(x, dp[i+1][j]+1);
                    x = min(x, dp[i][j+1]+1);
                }
            }
        }

        return dp[len1][len2];
    }
};
