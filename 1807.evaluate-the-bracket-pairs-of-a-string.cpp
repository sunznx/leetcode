// CreateTime: 2021-03-28 10:58:55
class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> m;
        for (auto &x: knowledge) {
            m[x[0]] = x[1];
        }

        bool flag = false;
        string sub = "";
        string ans = "";
        int len = s.size();
        for (int k = 0; k < len; k++) {
            auto x = s[k];
            if (x == ')') {
                flag = false;

                auto replace = m[sub];
                if (replace != "") {
                    ans += replace;
                } else {
                    ans += "?";
                }
                sub = "";
            } else if (flag) {
                sub = sub + x;
            } else if (x == '(') {
                flag = true;
            } else {
                ans += x;
            }
        }
        return ans;
    }
};