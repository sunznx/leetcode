// CreateTime: 2021-04-01 23:43:30
class Solution {
public:
    vector<string> ans;
    vector<string> que;

    vector<string> restoreIpAddresses(string s) {
        dfs(s, 0, "");
        return ans;
    }

    void dfs(string &s, int step, string pre) {
        if (que.size() > 4) {
            return;
        }

        if (step == s.size()) {
            if (que.size() == 3 && pre.size()) {
                ans.push_back(que[0] + "." + que[1] + "." + que[2] + "." + pre);
            }
            return;
        }

        auto x = s[step];

        if (pre == "0") {
            que.push_back(pre);
            dfs(s, step+1, string(1, x));
            que.pop_back();
            return;
        }

        if (pre.size()) {
            que.push_back(pre);
            dfs(s, step+1, string(1, x));
            que.pop_back();

            if (check(pre+x)) {
                dfs(s, step+1, pre+x);
            }
        } else {
            dfs(s, step+1, string(1, x));
        }
    }

    bool check(string s) {
        return stoi(s) <= 255;
    }
};
