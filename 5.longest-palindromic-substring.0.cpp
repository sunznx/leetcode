// CreateTime: 2021-03-01 16:13:23
class Solution {
public:
    string ans = "";

    string longestPalindrome(string s) {
        int len = s.size();
        vector<vector<int>> f(len+1, vector<int>(len+1, 0));

        for (int i = 0; i < len; i++) {
            f[i][i] = 1;
            if (i+1 < len && s[i] == s[i+1]) {
                f[i][i+1] = 2;
            }
        }

        for (int sz = 3; sz <= len; sz++) {
            for (int i = 0; i+sz-1 < len; i++) {
                int j = i+sz-1;
                if (s[i] == s[j] && f[i+1][j-1] > 0) {
                    f[i][j] = f[i+1][j-1] + 2;
                }
            }
        }

        for (int sz = 1; sz <= len; sz++) {
            for (int i = 0; i+sz-1 < len; i++) {
                int j = i+sz-1;

                if (f[i][j] > ans.size()) {
                    ans = s.substr(i, sz);
                }
            }
        }

        return ans;
    }
};
