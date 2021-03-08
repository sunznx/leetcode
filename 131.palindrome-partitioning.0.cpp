// CreateTime: 2021-03-08 16:29:18
class Solution {
public:
    vector<vector<string>> ans;
    vector<vector<bool>> dp;
    vector<vector<int>> m;

    vector<vector<string>> partition(string s) {
        int len = s.size();
        dp.resize(len+1, vector<bool>(len+1));
        m.resize(len+1, vector<int>(len+1, -1));

        for (int i = 0; i < len; i++) {
            dp[i][i] = true;
            if (i > 0 && s[i] == s[i-1]) {
                dp[i-1][i] = true;
            }
        }

        for (int i = len-1; i >= 0; i--) {
            for (int j = i+2; j < len; j++) {
                if ((dp[i+1][j-1]) && s[i] == s[j]) {
                    dp[i][j] = true;
                }
            }
        }

        dfs(s, len, 0, len-1);
        return ans;
    }

    void dfs(string &s, int len, int i, int j, vector<string> sub = {}) {
        if (i > j && sub.size()) {
            ans.push_back(sub);
            return;
        }

        for (int k = i; k <= j; k++) {
            if (dp[i][k]) {
                sub.push_back(s.substr(i, k-i+1));
                dfs(s, len, k+1, len-1, sub);
                sub.pop_back();
            }
        }
    }
};
