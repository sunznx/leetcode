// CreateTime: 2020-12-08 15:55:12
class Solution {
public:
    int pos;
    string exp;

    string countOfAtoms(string formula) {
        pos = 0;
        exp = formula;

        string ans;
        auto m = parse();
        for (auto &x: m) {
            if (x.second == 1) {
                ans = ans + x.first;
            } else {
                ans = ans + x.first + to_string(x.second);
            }
        }
        return ans;
    }

    map<string, int> parse() {
        map<string, int> m;

        while (!isEnd()) {
            auto r = next();
            match(r, m);
        }

        return m;
    }

    void mergeMap(map<string, int> &m, map<string, int> &subM) {
        for (auto &x: subM) {
            m[x.first] += x.second;
        }
    }

    void match(string r, map<string, int> &m) {
        if (isLeftParen(r)) {
            auto subM = parseLeft();
            mergeMap(m, subM);
        } else if (isAtom(r)) {
            auto nextRead = peek();
            if (isNum(nextRead)) {
                next();
                m[r] += stoi(nextRead);
            } else {
                m[r] += 1;
            }
        }
    }

    map<string, int> parseLeft() {
        map<string, int> m;

        while (true) {
            auto r = next();
            if (isRightParen(r)) {
                break;
            }

            match(r, m);
        }

        int base = 1;

        auto r = peek();
        if (isNum(r)) {
            next();
            base = stoi(r);
        }

        for (auto &x: m) {
            x.second = x.second * base;
        }
        return m;
    }

    string next() {
        auto r = peek();
        pos += r.size();
        return r;
    }


    string peek() {
        if (exp[pos] == '(') {
            return "(";
        }

        if (exp[pos] == ')') {
            return ")";
        }

        int k = pos;
        string ans;

        if (isUpper(exp[pos])) {
            ans.push_back(exp[k++]);
            if (!isEnd(k) && isLower(exp[k])) {
                ans.push_back(exp[k++]);
            }
            return ans;
        }

        if (isNum(exp[k])) {
            while (!isEnd(k) && isNum(exp[k])) {
                ans.push_back(exp[k++]);
            }
            return ans;
        }
        return "";
    }

    bool isEnd() {
        return pos == exp.size();
    }
    
    bool isEnd(int k) {
        return k == exp.size();
    }

    bool isLeftParen(string &s) {
        return s == "(";
    }

    bool isRightParen(string &s) {
        return s == ")";
    }

    bool isAtom(string &x) {
        return isAtom(x[0]);
    }

    bool isUpper(char &x) {
        return 'A' <= x && x <= 'Z';
    }

    bool isLower(char &x) {
        return 'a' <= x && x <= 'z';
    }

    bool isNum(string &x) {
        return isNum(x[0]);
    }

    bool isAtom(char &x) {
        return 'a' <= x && x <= 'z' || 'A' <= x && x <= 'Z';
    }

    bool isNum(char &x) {
        return '0' <= x && x <= '9';
    }
};
