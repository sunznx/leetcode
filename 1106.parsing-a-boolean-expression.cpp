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
            char r = exp[pos];

            if (r == ')') {
                pos++;
                break;
            }

            if (r == '(' || r == ',' || r == ' ' || r == '\t') {
                pos++;
                continue;
            }

            if (r == 't') {
                pos++;
                v = true;
            }

            if (r == 'f') {
                pos++;
                v = false;
            }

            if (r == '&') {
                pos++;
                v = parseBracket(true);
            }
            if (r == '|') {
                pos++;
                v = parseBracket(false);
            }
            if (r == '!') {
                pos++;
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
