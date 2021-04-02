// CreateTime: 2021-04-01 23:43:30
class Solution {
public:
    vector<string> ans;
    vector<string> que;

    // 思路，将 s 分割成 4 个字符串数组
    vector<string> restoreIpAddresses(string s) {
        dfs(s, 0);
        return ans;
    }

    void dfs(string &s, int step) {
        if (que.size() > 4) {
            return;
        }

        // 走到末尾了，检查答案是否合法
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

        if (que.size() && check(que.back()+x)) {
            que.back().push_back(x);
            dfs(s, step+1);
            que.back().pop_back();
        }

        que.push_back(string(1, x));
        dfs(s, step+1);
        que.pop_back();
    }

    bool check(string s) {
        return stoi(s) <= 255;
    }
};
