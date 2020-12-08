// CreateTime: 2020-12-08 08:46:36
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;

        for (int i = 0; i < s.size(); i++) {
            auto x = s[i];

            stk.push(x);

            if (x == 'a') {
                continue;
            }

            if (x == 'b') {
                if (!(stk.size() >= 2)) {
                    return false;
                }

                auto b = stk.top();
                stk.pop();

                auto a = stk.top();
                stk.pop();

                if (!(a == 'a' && b == 'b')) {
                    return false;
                }

                stk.push(a);
                stk.push(b);

                continue;
            }

            if (x == 'c') {
                if (!(stk.size() >= 3)) {
                    return false;
                }

                auto c = stk.top();
                stk.pop();

                auto b = stk.top();
                stk.pop();

                auto a = stk.top();
                stk.pop();

                if (!(a == 'a' && b == 'b' && c == 'c')) {
                    return false;
                }
            }
        }

        return stk.empty();
    }
};
