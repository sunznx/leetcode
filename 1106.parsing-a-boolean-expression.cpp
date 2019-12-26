// CreateTime: 2019-12-25 10:38:01
class Solution {
public:
    int read = 0;
    string expression;

    bool isEnd() {
        return read == expression.size();
    }

    bool parseBoolExpr(string expression) {
        this->expression = expression;
        return parseBracket(true);
    }

    bool parseBracket(bool AND) {
        bool isFirst = true;
        bool res = true;
        bool v;
        char r;

        while (!isEnd()) {
            r = expression[read];

            if (r == ')') {
                read++;
                break;
            }

            if (r == '(' || r == ',' || r == ' ' || r == '\t') {
                read++;
                continue;
            }

            if (r == 't') {
                read++;
                v = true;
            }

            if (r == 'f') {
                read++;
                v = false;
            }

            if (r == '&') {
                read++;
                v = parseBracket(true);
            }
            if (r == '|') {
                read++;
                v = parseBracket(false);
            }
            if (r == '!') {
                read++;
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
