class Solution {
public:
    bool isValid(string str) {
        int len = str.size();

        stack<char> s;

        for (int i = 0; i < len; i++) {
            // push
            if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
                s.push(str[i]);
            } else {
                if (s.size() == 0) {
                    return false;
                }
                
                char c = s.top();

                if (str[i] == ')') {
                    if (c != '(') {
                        return false;
                    }
                } else if (str[i] == '}') {
                    if (c != '{') {
                        return false;
                    }
                } else if (str[i] == ']') {
                    if (c != '[') {
                        return false;
                    }
                }

                s.pop();
            }
        }
        if (s.size() != 0) {
            return false;
        }
        return true;
    }
};
