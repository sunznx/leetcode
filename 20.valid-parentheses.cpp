// CreateTime: 2020-12-02 23:40:21
class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2 == 1) {
            return false;
        }

        stack<char> stk;

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];

            if (isLeft(c)) {
                stk.push(c);
            } else {
                if (stk.empty()) {
                    return false;
                }

                auto x = stk.top();
                stk.pop();

                if (!match(x, c)) {
                    return false;
                }
            }
        }

        while (stk.size()) {
            auto c1 = stk.top();
            stk.pop();

            auto c2 = stk.top();
            stk.pop();

            if (!match(c2, c1)) {
                return false;
            }
        }

        return stk.empty();
    }

    bool isLeft(char c) {
        return c == '(' || c == '{' || c == '[';
    }

    bool match(char l, char r) {
        return (l == '(' && r == ')') || (l == '{' && r == '}') || (l == '[' && r == ']');
    }
};
