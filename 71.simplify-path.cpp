// CreateTime: 2020-01-02 16:49:56
class Solution {
public:
    string simplifyPath(string path) {
        int len = path.size();

        stack<string> s;
        string sub = "";

        for (int i = 0; i < len; i++) {
            char c = path[i];
            if (c != '/') {
                sub = sub + c;
            }

            if (c == '/' || i == len-1) {
                if (sub == "..") {
                    if (s.size()) {
                        s.pop();
                    }
                } else if (sub != "" && sub != ".") {
                    s.push("/" + sub);
                }
                sub = "";
            }
        }

        if (s.size() == 0) {
            return "/";
        }

        string res = "";
        while (s.size()) {
            res = s.top() + res;
            s.pop();
        }
        return res;
    }
};
