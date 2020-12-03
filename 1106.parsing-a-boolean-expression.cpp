// CreateTime: 2019-12-25 10:38:01
class Solution {
public:
    int pos;
    string exp;

    bool isEnd() {
        return pos == exp.size();
    }

    bool parseBoolExpr(string expression) {
        pos = 0;
        exp = expression;
        return parseBracket();
    }

    bool parseBracket(bool AND = true) {
        bool isFirst = true;
        bool res = true;
        bool v = true;

        while (!isEnd()) {
            char r = exp[pos++];

            if (r == ')') {
                break;
            }

            else if (r == '(' || r == ',' || r == ' ' || r == '\t') {
                continue;
            }

            else if (r == 't') {
                v = true;
            }

            else if (r == 'f') {
                v = false;
            }

            else if (r == '&') {
                v = parseBracket(true);
            }

            else if (r == '|') {
                v = parseBracket(false);
            }

            else if (r == '!') {
                v = !parseBracket(true);
            }

            if (isFirst) {
                isFirst = false;
                res = v;
            } else if (AND == true) {
                res = res && v;
            } else if (AND == false) {
                res = res || v;
            }
        }

        return res;
    }
};
