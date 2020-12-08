// CreateTime: 2020-01-02 16:49:56
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stk;
        auto pathArr = split(path, '/');
        for (int i = 0; i < pathArr.size(); i++) {
            auto x = pathArr[i];

            if (x == "." || x == "") {
                continue;
            }
            else if (x == "..") {
                if (stk.size()) {
                    stk.pop_back();
                }
            }
            else {
                stk.push_back(x);
            }
        }

        return "/" + join(stk, '/');
    }

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

    string join(vector<string> &arr, char x) {
        string ans = "";
        for (int i = 0; i < arr.size(); i++) {
            if (i == arr.size()-1) {
                ans = ans + arr[i];
            } else {
                ans = ans + arr[i] + x;
            }
        }
        return ans;
    }
};
