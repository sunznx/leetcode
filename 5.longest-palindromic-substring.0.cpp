// CreateTime: 2021-03-01 16:13:23
class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size();
        string ans = string(1, s[0]);
        vector<vector<bool>> f(len+1, vector<bool>(len+1, true));

        for (int i = len-1; i >= 0; i--) {
            for (int j = i+1; j < len; j++) {
                if (!(s[i] == s[j] && f[i+1][j-1])) {
                    f[i][j] = false;
                }

                auto sz = j-i+1;
                if (f[i][j] && sz > ans.size()) {
                    ans = s.substr(i, sz);
                }
            }
        }

        return ans;
    }
};
