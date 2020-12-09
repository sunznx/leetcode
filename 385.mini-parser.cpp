// CreateTime: 2020-12-03 02:49:26
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    int pos;
    string exp;

    NestedInteger deserialize(string s) {
        pos = 0;
        exp = s;
        return parse();
    }

    NestedInteger parse() {
        auto r = next();
        if (isLeft(r)) {
            return parseLeft();
        }

        NestedInteger ans;
        ans.setInteger(stoi(r));
        return ans;
    }

    NestedInteger parseLeft() {
        NestedInteger ans;
        while (true) {
            auto r = next();
            if (isRight(r)) {
                break;
            }
            match(r, ans);
        }
        return ans;
    }

    void match(string &r, NestedInteger &ans) {
        if (isLeft(r)) {
            NestedInteger sub = parseLeft();
            ans.add(sub);
        }

        else if (isComma(r)) {
            return;
        }

        else if (isNum(r)) {
            if (!ans.isInteger()) {
                ans.add(stoi(r));
            } else {
                ans.setInteger(stoi(r));
            }
        }
    }

    bool isEnd() {
        return isEnd(pos);
    }

    bool isEnd(int k) {
        return k == exp.size();
    }

    string peak() {
        while (!isEnd() && (isSpace(exp[pos]))) {
            pos++;
        }

        int k = pos;

        if (isLeft(exp[k])) {
            return "[";
        }

        if (isRight(exp[k])) {
            return "]";
        }

        if (isComma(exp[k])) {
            return ",";
        }

        string ans;
        while (!isEnd(k) && isNum(exp[k])) {
            ans.push_back(exp[k++]);
        }
        return ans;
    }

    string next() {
        auto r = peak();
        pos += r.size();
        return r;
    }

    bool isNum(string &s) {
        return isNum(s[0]);
    }

    bool isNum(char &c) {
        return '0' <= c && c <= '9' || c == '-';
    }

    bool isLeft(string &s) {
        return isLeft(s[0]);
    }

    bool isLeft(char &s) {
        return s == '[';
    }

    bool isRight(string &s) {
        return isRight(s[0]);
    }

    bool isRight(char &c) {
        return c == ']';
    }

    bool isComma(string &s) {
        return isComma(s[0]);
    }

    bool isComma(char &c) {
        return c == ',';
    }

    bool isSpace(string &s) {
        return isSpace(s[0]);
    }

    bool isSpace(char &c) {
        return c == ' ';
    }
};
