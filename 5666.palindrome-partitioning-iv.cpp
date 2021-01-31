// CreateTime: 2021-01-31 10:59:37
class Solution {
public:
    vector<vector<bool>> f;

    bool checkPartitioning(string s) {
        int len = s.size();
        f.resize(len, vector<bool>(len));

        for (int i = 0; i < len; i++) {
            f[i][i] = true;
            if (i < len-1 && s[i] == s[i+1]) {
                f[i][i+1] = true;
            }
        }

        for (int l = 3; l <= len; l++) {
            for (int i = 0; i+l-1 < len; i++) {
                auto j = i+l-1;
                if (s[i] == s[j]) {
                    f[i][j] = f[i+1][j-1];
                }
            }
        }

        for (int i = 1; i < len; i++) {
            auto s1 = s.substr(0, i);
            if (!f[0][i-1]) {
                continue;
            }

            for (int j = 1; j+i < len; j++) {
                if (!f[i][i+j-1]) {
                    continue;
                }

                if (f[i+j][len-1]) {
                    return true;
                }
            }

        }
        return false;
    }
};