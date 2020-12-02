// CreateTime: 2020-12-02 01:42:41
class Solution {
public:
    string removeKdigits(string num, int k) {
        deque<char> q;

        int removed = 0;

        for (int i = 0; i < num.size(); i++) {
            while (removed < k && !q.empty() && q.back() > num[i]) {
                q.pop_back();
                removed++;
            }
            q.push_back(num[i]);
        }

        string ans;
        for (int i = 0; i < num.size()-k; i++) {
            // 去掉前导 0
            if (q.front() == '0' && ans.size() == 0) {
                q.pop_front();
                continue;
            }

            ans.push_back(q.front());
            q.pop_front();
        }

        // 空字符串变成 0
        if (ans.size() == 0) {
            ans = "0";
        }

        return ans;
    }
};
