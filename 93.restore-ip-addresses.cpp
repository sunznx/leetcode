// CreateTime: 2021-04-01 23:43:30
class Solution {
public:
    vector<string> ans;
    vector<string> que;

    // 思路，将 s 分割成 4 个字符串数组
    vector<string> restoreIpAddresses(string s) {
        dfs(s, 0, "");
        return ans;
    }

    // pre 表示已经走过，但是还没被放到 que 里面的字符串
    void dfs(string &s, int step, string pre) {
        if (que.size() >= 4) {
            return;
        }

        // 走到末尾了，检查答案是否合法
        if (step == s.size()) {
            if (que.size() == 3 && pre.size()) {
                ans.push_back(que[0] + "." + que[1] + "." + que[2] + "." + pre);
            }
            return;
        }

        auto x = s[step];

        // pre 是 0 开头的
        // 说明 pre 后面不能再和其他字符合并了
        if (pre == "0") {
            que.push_back(pre);
            dfs(s, step+1, string(1, x));
            que.pop_back();
            return;
        }

        // 如果 pre 有值，说明我们接下来有两种走法
        // 1. 将 pre 放到 que 里面，说明 pre 这个字符串已经被消耗了
        // 2. 不消耗 pre，将 pre+x 合并成一个新的 pre
        if (pre.size()) {
            que.push_back(pre);
            dfs(s, step+1, string(1, x));
            que.pop_back();

            if (check(pre+x)) {
                dfs(s, step+1, pre+x);
            }
        }

        // 如果 pre 没有值
        // 只有一种走法，x 作为新的 pre
        else {
            dfs(s, step+1, string(1, x));
        }
    }

    bool check(string s) {
        return stoi(s) <= 255;
    }
};
