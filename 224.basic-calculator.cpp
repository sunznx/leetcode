// CreateTime: 2020-12-03 00:49:28
class Solution
{
public:
    int pos;
    string exp;

    int calculate(string s) {
        pos = 0;
        exp = s;
        return parse();
    }

    int parse() {
        int ans = 0;
        while (!isEnd()) {
            auto r = next();
            match(r, ans);
        }

        return ans;
    }

    int parseLeft() {
        int ans = 0;

        while (true) {
            auto r = next();
            if (isRight(r)) {
                break;
            }
            match(r, ans);
        }
        return ans;
    }

    void match(string &r, int &ans, bool isAdd = true) {
        if (isLeft(r)) {
            auto sub = parseLeft();
            if (isAdd) {
                ans += sub;
            } else {
                ans -= sub;
            }
        }

        else if (isNum(r)) {
            if (isAdd) {
                ans += stoi(r);
            } else {
                ans -= stoi(r);
            }
        }

        else if (isAddOp(r)) {
            r = next();
            match(r, ans, true);
        }

        else if (isSubOp(r)) {
            r = next();
            match(r, ans, false);
        }
    }

    string peek() {
        while (!isEnd() && isSpace(exp[pos])) {
            pos++;
        }

        int k = pos;

        if (isLeft(exp[k])) {
            return "(";
        }

        if (isRight(exp[k])) {
            return ")";
        }

        if (isAddOp(exp[k])) {
            return "+";
        }

        if (isSubOp(exp[k])) {
            return "-";
        }

        string ans;
        while (!isEnd(k) && isNum(exp[k])) {
            ans.push_back(exp[k++]);
        }
        return ans;
    }

    string next() {
        auto r = peek();
        pos += r.size();
        return r;
    }

    bool isEnd() {
        return isEnd(pos);
    }

    bool isEnd(int k) {
        return k == exp.size();
    }

    int calc(int &v, bool isAdd) {
        if (isAdd) {
            return v;
        }
        return -v;
    }

    bool isAddOp(char &c) {
        return c == '+';
    }

    bool isSubOp(char &c) {
        return c == '-';
    }

    bool isAddOp(string &s) {
        return isAddOp(s[0]);
    }

    bool isSubOp(string &s) {
        return isSubOp(s[0]);
    }

    bool isLeft(string &s) {
        return isLeft(s[0]);
    }

    bool isLeft(char &c) {
        return c == '(';
    }

    bool isRight(string &s) {
        return isRight(s[0]);
    }

    bool isRight(char &c) {
        return c == ')';
    }

    bool isNum(char &c) {
        return '0' <= c && c <= '9';
    }

    bool isNum(string &s) {
        return isNum(s[0]);
    }

    bool isSpace(char &c) {
        return c == ' ';
    }

    bool isSpace(string &s) {
        return isSpace(s[0]);
    }
};