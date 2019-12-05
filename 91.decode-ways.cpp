// CreateTime: 2019-12-05 22:12:05
class Solution {
public:
    int res;

    int numDecodings(string s) {
        res = 0;
        int len = s.size();
        dfs(s, 0);
        return res;
    }
    
    void dfs(string &s, int step) {
        if (step == s.size()) {
            res += 1;
            return;
        }

        int v = s[step]-'0';
        if (v == 0) {
            return;
        }

        if (step+1 <= s.size()-1) {
            int n = s[step+1]-'0';
            if (v*10 + n <= 26) {
                dfs(s, step+2);
            }
        }
        dfs(s, step+1);
    }
};
