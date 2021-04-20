// CreateTime: 2021-04-21 00:29:26
class Solution {
public:
    int ans = 0;
    char prev = 'x';
    vector<vector<int>> m;

    int numDecodings(string s) {
        m.resize(2, vector<int>(s.size()+1, -1));
        return dfs(s);
    }

    int dfs(string &s, int step = 0, int state = 0) {
        if (step == s.size()) {
            return 1;
        }

        auto &k = m[state][step];
        if (k >= 0) {
            return k;
        }

        k = 0;
        if (state == 1 && ((s[step-1] == '1') || (s[step-1] == '2' && '0' <= s[step] && s[step] <= '6'))) {
            k += dfs(s, step+1, 0);
        }

        if (s[step] != '0') {
            k += dfs(s, step+1, 1);
        }

        return k;
    }
};
