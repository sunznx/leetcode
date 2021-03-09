// CreateTime: 2021-03-09 08:13:17
class Solution {
public:
    int minCut(string s) {
        int len = s.size();
        vector<vector<bool>> f(len+1, vector<bool>(len+1, true));

        for (int i = len-1; i >= 0; i--) {
            for (int j = i+1; j < len; j++) {
                if (!(s[i] == s[j] && f[i+1][j-1])) {
                    f[i][j] = false;
                }
            }
        }

        vector<int> g(len, len-1);
        for (int i = 0; i < len; i++) {
            if (f[0][i]) {
                g[i] = 0;
            } else {
                for (int j = 0; j < i; j++) {
                    if (f[j+1][i]) {
                        g[i] = min(g[i], g[j]+1);
                    }
                }
            }
        }
        return g[len-1];
    }
};
