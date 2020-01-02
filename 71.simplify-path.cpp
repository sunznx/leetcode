// CreateTime: 2020-01-02 16:49:56
class Solution {
public:
    string simplifyPath(string path) {
        stack<string> s;

        int len = path.size();
        string v = "";
        for (int i = 0; i < len; i++) {
            if (path[i] != '/') {
                v = v + path[i];
            }

            if (path[i] == '/' || i == len-1) {
                if (v == "..") {
                    if (s.size()) {
                        s.pop();
                    }
                } else if (v != "" && v != ".") {
                    s.push("/" + v);
                }
                v = "";
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
