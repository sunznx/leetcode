// CreateTime: 2020-12-03 00:32:21
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;

        for (int i = 0; i < tokens.size(); i++) {
            auto token = tokens[i];

            if (isOp(token)) {
                auto t1 = stk.top();
                stk.pop();

                auto t2 = stk.top();
                stk.pop();

                stk.push(op(token, t2, t1));
            } else {
                auto x = stoi(token);
                stk.push(x);
            }
        }

        return stk.top();
    }

    bool isOp(string &s) {
        return (s == "+") || (s == "-") || (s == "*") || (s == "/");
    }

    int op(string &s, int &n1, int &n2) {
        if (s == "+") {
            return n1 + n2;
        }

        if (s == "-") {
            return n1 - n2;
        }

        if (s == "*") {
            return n1 * n2;
        }

        if (s == "/") {
            return n1 / n2;
        }

        return 1;
    }
};
