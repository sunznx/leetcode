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

    string read() {
        string ans = string(1, exp[pos++]);
        if (!isNum(ans[0])) {
            return ans;
        }

        while (pos != exp.size() && isNum(exp[pos])) {
            ans.push_back(exp[pos++]);
        }
        return ans;
    }

    int parse(bool isAdd = true) {
        int ans = 0;
        while (!isEnd()) {
            auto sub = read();

            if (sub == " ") {
                continue;
            }

            else if (isLeft(sub)) {
                auto v = parse();
                ans += calc(v, isAdd);
            }

            else if (isRight(sub)) {
                break;
            }

            else if (isAddOp(sub)) {
                isAdd = true;
            }

            else if (isSubOp(sub)) {
                isAdd = false;
            }

            else {
                auto v = stoi(sub);
                ans += calc(v, isAdd);
            }
        }

        return ans;
    }

    bool isEnd() {
        return pos == exp.size();
    }

    int calc(int &v, bool isAdd) {
        if (isAdd) {
            return v;
        }
        return -v;
    }

    bool isAddOp(string &s) {
        return s == "+";
    }

    bool isSubOp(string &s) {
        return s == "-";
    }

    bool isLeft(string &s) {
        return s == "(";
    }

    bool isRight(string &s) {
        return s == ")";
    }

    bool isNum(char c) {
        return '0' <= c && c <= '9';
    }
};