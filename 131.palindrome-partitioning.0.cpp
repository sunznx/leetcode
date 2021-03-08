// CreateTime: 2021-03-08 16:29:18
class Solution {
public:
    vector<vector<string>> ans;
    vector<vector<bool>> dp;

    vector<vector<string>> partition(string s) {
        int len = s.size();
        dp.resize(len+1, vector<bool>(len+1));

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

        vector<string> empty;
        dfs(s, len, 0, empty);
        return ans;
    }

    void dfs(string &s, int len, int step, vector<string> &sub) {
        if (step == len && sub.size()) {
            ans.push_back(sub);
            return;
        }

        for (int k = step; k <= len-1; k++) {
            if (dp[step][k]) {
                sub.push_back(s.substr(step, k-step+1));
                dfs(s, len, k+1, sub);
                sub.pop_back();
            }
        }
    }
};
