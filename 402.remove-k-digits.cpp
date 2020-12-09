// CreateTime: 2020-12-02 01:42:41
class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans;
        int removed = 0;
        for (int i = 0; i < num.size(); i++) {
            auto x = num[i];
            while (removed < k && ans.size() && x < ans.back()) {
                ans.pop_back();
                removed++;
            }
            ans.push_back(x);
        }

        // 后面的全部删除
        ans = ans.substr(0, num.size()-k);
        while (ans.size() && ans[0] == '0') {
            ans.erase(ans.begin());
        }

        // 空字符串变成 0
        if (ans.size() == 0) {
            return "0";
        }

        return ans;
    }
};
