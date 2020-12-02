// CreateTime: 2020-12-02 07:37:13
class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> q;

        int removed = 0;

        for (int i = 0; i < num.size(); i++) {
            while (removed < k && !q.empty() && q.top() > num[i]) {
                q.pop();
                removed++;
            }
            q.push(num[i]);
        }

        // 移除多余的数字
        while (q.size() > num.size()-k) {
            q.pop();
        }

        string ans;
        while (q.size()) {
            ans.insert(ans.begin(), q.top());
            q.pop();
        }

        // 去掉前导 0
        while (ans.size() && ans[0] == '0') {
            ans = ans.substr(1);
        }

        // 空字符串变成 0
        if (ans.size() == 0) {
            ans = "0";
        }

        return ans;
    }
};
