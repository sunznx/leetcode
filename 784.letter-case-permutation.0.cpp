class Solution {
public:
    vector<string> res;
    vector<string> letterCasePermutation(string S) {

        dfs(S, S, 0);
        return res;
    }

    void dfs(string s, string t, int step) {
        if (step == s.size()) {
            res.push_back(t);
            return;
        }

        t[step] = s[step];
        dfs(s, t, step+1);

        if ('a' <= s[step] && s[step] <= 'z') {
            t[step] = s[step] - 32;
            dfs(s, t, step+1);
        }
        if ('A' <= s[step] && s[step] <= 'Z') {
            t[step] = s[step] + 32;
            dfs(s, t, step+1);
        }
    }
};
