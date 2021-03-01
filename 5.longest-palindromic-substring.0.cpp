// CreateTime: 2021-03-01 16:13:23
class Solution {
public:
    string ans = "";

    string longestPalindrome(string s) {
        int len = s.size();
        vector<vector<int>> f(len+1, vector<int>(len+1, 0));

        for (int sz = 1; sz <= len; sz++) {
            for (int i = 0; i+sz-1 < len; i++) {
                int j = i+sz-1;

                if (sz == 1) {
                    f[i][j] = 1;
                } else if (sz == 2 && s[i] == s[j]) {
                    f[i][j] = 2;
                } else {        // 大于 3 的情况
                    if (s[i] == s[j] && f[i+1][j-1] > 0) {
                        f[i][j] = f[i+1][j-1] + 2;
                    }
                }

                if (f[i][j] > ans.size()) {
                    ans = s.substr(i, sz);
                }
            }
        }

        return ans;
    }
};
