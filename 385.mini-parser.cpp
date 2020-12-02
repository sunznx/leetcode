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

    NestedInteger parse(bool inList = false) {
        NestedInteger ans;
        while (!isEnd()) {
            auto sub = read();

            if (sub == " ") {
                continue;
            }
            else if (isRight(sub)) {
                break;
            }
            else if (isComma(sub)) {
                continue;
            }
            else if (isLeft(sub)) {
                auto v = parse(true);
                if (inList) {
                    ans.add(v);
                } else {
                    ans = v;
                }
            }
            else {
                auto v = stoi(sub);
                if (inList) {
                    ans.add(NestedInteger(v));
                } else {
                    ans.setInteger(v);
                }
            }
        }
        return ans;
    }

    bool isEnd() {
        return pos == exp.size();
    }

    string read() {
        string ans(1, exp[pos++]);
        if (!isNum(ans[0])) {
            return ans;
        }

        while (pos < exp.size() && isNum(exp[pos])) {
            ans.push_back(exp[pos++]);
        }
        return ans;
    }

    bool isNum(char &c) {
        return '0' <= c && c <= '9' || c == '-';
    }

    bool isLeft(string &s) {
        return s == "[";
    }

    bool isRight(string &s) {
        return s == "]";
    }

    bool isComma(string &s) {
        return s == ",";
    }
};
