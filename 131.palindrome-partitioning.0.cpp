// CreateTime: 2021-03-08 16:29:18
class Solution {
public:
    vector<vector<string>> ans;
    vector<vector<bool>> dp;
    vector<string> sub;

    vector<vector<string>> partition(string s) {
        int len = s.size();
        dp.resize(len+1, vector<bool>(len+1, true));
        for (int i = len-1; i >= 0; i--) {
            for (int j = i+1; j < len; j++) {
                if (!(s[i] == s[j] && dp[i+1][j-1])) {
                    dp[i][j] = false;
                }
            }
        }

        dfs(s);
        return ans;
    }

    void dfs(string &s, int step = 0) {
        int len = s.size();
        if (step == len) {
            ans.push_back(sub);
            return;
        }

        for (int k = step; k <= len-1; k++) {
            if (dp[step][k]) {
                sub.push_back(s.substr(step, k-step+1));
                dfs(s, k+1);
                sub.pop_back();
            }
        }
    }
};
