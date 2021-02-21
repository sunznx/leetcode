// CreateTime: 2021-02-21 11:13:51
class Solution {
public:
    int longestPalindrome(string word1, string word2) {
        int ans = 0;
        int len1 = word1.size();
        int len2 = word2.size();

        string s = word1 + word2;
        int len = s.size();
        vector<vector<int>> f(len+1, vector<int>(len+1));

        for (int i = len-1; i >= 0; i--) {
            f[i][i] = 1;
            for (int j = i+1; j < len; j++) {
                if (s[i] == s[j]) {
                    f[i][j] = max(f[i][j], f[i+1][j-1]+2);
                    if (i < len1 && j >= len1) {
                        ans = max(ans, f[i][j]);
                    }
                } else {
                    f[i][j] = max(f[i+1][j], f[i][j-1]);
                }
            }
        }

        return ans;
    }
};