// CreateTime: 2021-03-15 20:03:50
class Solution {
public:
    int countSubstrings(string s) {
        int len = s.size();
        vector<vector<bool>> f(len+1, vector<bool>(len+1, true));

        int ans = 0;
        for (int i = len-1; i >= 0; i--) {
            ans++;
            for (int j = i+1; j < len; j++) {
                if (!(s[i] == s[j] && f[i+1][j-1])) {
                    f[i][j] = false;
                }

                if (f[i][j]) {
                    ans++;
                }
            }
        }
        return ans;
    }
};
