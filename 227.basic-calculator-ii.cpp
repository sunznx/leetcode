// CreateTime: 2019-12-05 22:41:24
class Solution {
public:
    int calculate(string s) {
        int v = 0;
        stack<int> stk;

        int len = s.size();
        for (int i = 0; i < len; i++) {
            if ('0' <= s[i] && s[i] <= '9') {
                v = v * 10 + (s[i] - '0');
            }

            if (!('0' <= s[i] && s[i] <= '9') && s[i] != ' ' || i == len-1) {
                if (stk.size() && (stk.top() == '*' || stk.top() == '/')) {
                    char op = stk.top();
                    stk.pop();

                    int num = stk.top();
                    stk.pop();

                    if (op == '*') {
                        stk.push(num * v);
                    } else {
                        stk.push(num / v);
                    }
                } else {
                    stk.push(v);
                }

                v = 0;
            }

            if (!('0' <= s[i] && s[i] <= '9') && s[i] != ' ') {
                stk.push(s[i]);
            }
        }

        int res = 0;
        while (stk.size()) {
            int top = stk.top();
            stk.pop();

            if (stk.size()) {
                char op = stk.top();
                stk.pop();
                if (op == '+') {
                    res += top;
                } else {
                    res -= top;
                }
            } else {
                res += top;
            }
        }

        return res;
    }
};