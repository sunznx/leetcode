// CreateTime: 2021-04-03 11:37:03
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int len1 = text1.size();
        int len2 = text2.size();

        vector<vector<int>> f(len1+1, vector<int>(len2+1));

        for (int i = 0; i < len1; i++) {
            for (int j = 0; j < len2; j++) {
                if (text1[i] == text2[j]) {
                    f[i+1][j+1] = f[i][j] + 1;
                } else {
                    f[i+1][j+1] = max(f[i+1][j], f[i][j+1]);
                }
            }
        }
        return f[len1][len2];
    }
};
