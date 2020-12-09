// CreateTime: 2019-12-25 10:38:01
class Solution {
public:
    int pos;
    string exp;

    int OP_AND = 0;
    int OP_OR = 1;
    int OP_NOT = 2;

    bool parseBoolExpr(string expanssion) {
        pos = 0;
        exp = expanssion;
        return parse();
    }

    bool parse() {
        auto r = next();
        if (isTrue(r)) {
            return true;
        }
        if (isFalse(r)) {
            return false;
        }
        return match(r);
    }

    bool parseAnd() {
        next();
        return parseLeft(OP_AND);
    }

    bool parseOr() {
        next();
        return parseLeft(OP_OR);
    }

    bool parseNot() {
        next();
        return parseLeft(OP_NOT);
    }

    bool parseLeft(int op) {
        bool ans;
        bool isFirst = true;

        while (true) {
            auto r = next();
            if (isRight(r)) {
                break;
            }

            auto sub = match(r);
            if (isFirst) {
                isFirst = false;
                ans = sub;
            } else {
                Op(op, ans, sub);
            }
        }

        if (op == OP_NOT) {
            return !ans;
        }
        return ans;
    }

    void Op(int &op, bool &ans, bool &sub) {
        if (op == OP_AND) {
            ans = (ans & sub);
        } else if (op == OP_OR) {
            ans = (ans | sub);
        } else if (op == OP_NOT) {
            ans = (ans & sub);
        }
    }

    bool match(string &r) {
        if (isAnd(r)) {
            return parseAnd();
        }
        else if (isOr(r)) {
            return parseOr();
        }
        else if (isNot(r)) {
            return parseNot();
        }
        else if (isTrue(r)) {
            return true;
        }
        else if (isFalse(r)) {
            return false;
        }
        return true;
    }

    string next() {
        auto r = peak();
        pos += r.size();
        return r;
    }

    string peak() {
        while (!isEnd() && (isSpace(exp[pos]) || isComma(exp[pos]))) {
            pos++;
        }

        int k = pos;
        if (isAnd(exp[k])) {
            return "&";
        }

        if (isOr(exp[k])) {
            return "|";
        }

        if (isNot(exp[k])) {
            return "!";
        }

        if (isTrue(exp[k])) {
            return "t";
        }

        if (isFalse(exp[k])) {
            return "f";
        }

        if (isLeft(exp[k])) {
            return "(";
        }

        if (isRight(exp[k])) {
            return ")";
        }

        return "";
    }

    bool isEnd() {
        return isEnd(pos);
    }

    bool isEnd(int k) {
        return k == exp.size();
    }

    bool isAnd(char &c) {
        return c == '&';
    }

    bool isOr(char &c) {
        return c == '|';
    }

    bool isNot(char &c) {
        return c == '!';
    }

    bool isTrue(char &c) {
        return c == 't';
    }

    bool isFalse(char &c) {
        return c == 'f';
    }

    bool isComma(char &c) {
        return c == ',';
    }

    bool isSpace(char &c) {
        return c == ' ' || c == '\t';
    }

    bool isLeft(char &c) {
        return c == '(';
    }

    bool isLeft(string &s) {
        return isLeft(s[0]);
    }

    bool isRight(char &c) {
        return c == ')';
    }

    bool isRight(string &s) {
        return isRight(s[0]);
    }

    bool isAnd(string &s) {
        return isAnd(s[0]);
    }

    bool isOr(string &s) {
        return isOr(s[0]);
    }

    bool isNot(string &s) {
        return isNot(s[0]);
    }

    bool isTrue(string &s) {
        return isTrue(s[0]);
    }

    bool isFalse(string &s) {
        return isFalse(s[0]);
    }

    bool isComma(string &s) {
        return isComma(s[0]);
    }

    bool isSpace(string &s) {
        return isSpace(s[0]);
    }
};