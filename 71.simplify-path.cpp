// CreateTime: 2020-01-02 16:49:56
class Solution {
public:
    vector<string> split(string &s, char x) {
        vector<string> ans;
        string sub = "";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != x) {
                sub.push_back(s[i]);
            }

            if (s[i] == x || i == s.size()-1) {
                ans.push_back(sub);
                sub = "";
            }
        }
        return ans;
    }

    string simplifyPath(string path) {
        stack<string> stk;
        auto pathArr = split(path, '/');
        for (int i = 0; i < pathArr.size(); i++) {
            auto x = pathArr[i];
            if (x == "." || x == "") {
                continue;
            } else if (x == "..") {
                if (stk.size()) {
                    stk.pop();
                }
            } else {
                stk.push(x);
            }
        }

        string ans = "";
        while (stk.size()) {
            auto x = stk.top();
            stk.pop();

            if (ans == "") {
                ans = x;
            } else {
                ans = x + "/" + ans;
            }
        }
        return "/" + ans;
    }
};
