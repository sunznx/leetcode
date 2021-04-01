// CreateTime: 2021-04-01 23:43:30
class Solution {
public:
    vector<string> ans;
    vector<string> sub;

    vector<string> restoreIpAddresses(string s) {
        dfs(s, 0, "");
        return ans;
    }

    void dfs(string &s, int step, string pre) {
        if (sub.size() > 4) {
            return;
        }

        if (step == s.size()) {
            if (sub.size() == 3 && pre.size()) {
                ans.push_back(sub[0] + "." + sub[1] + "." + sub[2] + "." + pre);
            }
            return;
        }

        auto x = s[step];

        if (pre == "0") {
            sub.push_back(pre);
            dfs(s, step+1, string(1, x));
            sub.pop_back();
            return;
        }

        if (pre.size() == 3 && check(pre)) {
            sub.push_back(pre);
            dfs(s, step+1, string(1, x));
            sub.pop_back();
            return;
        }

        if (pre.size() >= 3) {
            return;
        }

        if (pre.size()) {
            sub.push_back(pre);
            dfs(s, step+1, string(1, x));
            sub.pop_back();

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
