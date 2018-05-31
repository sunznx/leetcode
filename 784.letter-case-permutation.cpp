class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> res;
        dfs(res, s, 0);
        return res;
    }

    void dfs(vector<string> &res, string s, int n) {
        if (n == s.size()) {
            res.push_back(s);
            return;
        }

        char c = s[n];
        if ('a' <= s[n] && s[n] <= 'z') {
            dfs(res, s, n+1);
            s[n] = s[n] - 'a' + 'A';
            dfs(res, s, n+1);
            s[n] = c;
        } else if ('A' <= s[n] && s[n] <= 'Z') {
            dfs(res, s, n+1);
            s[n] = s[n] - 'A' + 'a';
            dfs(res, s, n+1);
            s[n] = c;
        } else {
            dfs(res, s, n+1);
        }
    }
};
