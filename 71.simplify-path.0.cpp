// CreateTime: 2020-12-02 23:53:12
class Solution {
public:
    string simplifyPath(string path) {
        stack<string> stk;

        string sub = "";
        for (int i = 0; i < path.size(); i++) {
            char c = path[i];
            if (c == '/') {
                if (sub.size()) {
                    stk.push(sub);
                } else {
                    stk.push("/");
                }
                sub = "/";
                continue;
            }

            sub.push_back(c);

            if (i == path.size()-1) {
                stk.push(sub);
                sub = "";
            }
        }

        string res = "";
        while (stk.size()) {
            auto sub = getTop(stk);
            if (sub == "/" && res.size() == 0) {
                res = "/";
            } else if (sub != "/") {
                res = sub + res;
            }
        }
        return res;
    }

    string getTop(stack<string> &stk) {
        while (stk.size()) {
            auto sub = stk.top();
            stk.pop();

            if (sub == "/" || sub == "/.") {
                continue;
            }

            if (sub == "/..") {
                getTop(stk);
                return getTop(stk);
            }

            return sub;
        }
        return "/";
    }
};