// CreateTime: 2021-04-01 23:43:30
class Solution {
public:
    vector<string> ans;
    vector<string> que;

    vector<string> restoreIpAddresses(string s) {
        dfs(s, 0);
        return ans;
    }

    void dfs(string &s, int step) {
        if (que.size() > 4) {
            return;
        }

        if (step == s.size()) {
            if (que.size() == 4) {
                ans.push_back(que[0] + "." + que[1] + "." + que[2] + "." + que[3]);                
            }
            return;
        }

        auto x = s[step];

        if (que.size() && que.back() == "0") {
            que.push_back(string(1, x));
            dfs(s, step+1);
            que.pop_back();
            return;
        }

        if (que.size() && stoi(que.back()+x) <= 255) {
            que.back().push_back(x);
            dfs(s, step+1);
            que.back().pop_back();
        }

        que.push_back(string(1, x));
        dfs(s, step+1);
        que.pop_back();
    }
};
