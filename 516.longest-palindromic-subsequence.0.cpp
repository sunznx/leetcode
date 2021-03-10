// CreateTime: 2021-03-10 21:00:18
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int len = s.size();

        vector<vector<int>> f(len+1, vector<int>(len+1));

        for (int i = len-1; i >= 0; i--) {
            f[i][i] = 1;
            for (int j = i+1; j < len; j++) {
                if (s[i] == s[j]) {
                    f[i][j] = max(f[i][j], f[i+1][j-1]+2);
                } else {
                    f[i][j] = max(f[i][j-1], f[i+1][j]);
                }
            }
        }

        return f[0][len-1];
    }
};
