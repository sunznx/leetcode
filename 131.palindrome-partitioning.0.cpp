// CreateTime: 2021-03-08 16:29:18
class Solution {
public:
    typedef pair<bool, string> PBS;
    vector<vector<string>> ans;
    vector<vector<PBS>> dp;
    vector<string> sub;

    vector<vector<string>> partition(string s) {
        int len = s.size();
        dp.resize(len+1, vector<PBS>(len+1));

        for (int i = 0; i < len; i++) {
            dp[i][i].first = true;
            dp[i][i].second.push_back(s[i]);

            if (i > 0 && s[i] == s[i-1]) {
                dp[i-1][i].first = true;
                dp[i-1][i].second = string(1, s[i-1]) + string(1, s[i]);
            }
        }

        for (int i = len-1; i >= 0; i--) {
            for (int j = i+2; j < len; j++) {
                if ((dp[i+1][j-1].first) && s[i] == s[j]) {
                    dp[i][j].first = true;
                    dp[i][j].second = string(1, s[i]) + dp[i+1][j-1].second + string(1, s[j]);
                }
            }
        }

        dfs(s, len, 0);
        return ans;
    }

    void dfs(string &s, int len, int step) {
        if (step == len) {
            ans.push_back(sub);
            return;
        }

        for (int k = step; k <= len-1; k++) {
            if (dp[step][k].first) {
                sub.push_back(dp[step][k].second);
                dfs(s, len, k+1);
                sub.pop_back();
            }
        }
    }
};
