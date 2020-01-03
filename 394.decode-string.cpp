// CreateTime: 2020-01-03 10:15:57
class Solution {
public:
    int k = 0;
    string expression;

    string decodeString(string s) {
        expression = s;
        string res = "";
        while (!isEnd()) {
            res += readNumAndBracket();
        }
        return res;
    }

    int readNum() {
        int res = 0;
        while (!isEnd() && isNum()) {
            res = res * 10 + (expression[k]-'0');
            k++;
        }
        return res;
    }

    string readString() {
        string res = "";
        while (!isEnd() && isAlpha()) {
            res = res + expression[k];
            k++;
        }
        return res;
    }

    string readNumAndBracket() {
        string res = "";
        int num = 1;
        if (!isEnd() && isNum()) {
            num = readNum();
        }
        return repeat(readBracket(), num);
    }

    string readBracket() {
        string res = "";
        while (!isEnd() && expression[k] != ']') {
            if (expression[k] == '[') {
                k++;
            }

            if (!isEnd() && isAlpha()) {
                res = res + readString();
            }

            if (!isEnd() && isNum()) {
                res += readNumAndBracket();
            }
        }
        if (!isEnd() && expression[k] == ']') {
            k++;
        }
        return res;
    }

    string repeat(string t, int times) {
        string res = "";
        while (times--) {
            res = res + t;
        }
        return res;
    }

    bool isEnd() {
        return k == expression.size();
    }

    bool isNum() {
        char c = expression[k];
        return '0' <= c && c <= '9';
    }

    bool isAlpha() {
        char c = expression[k];
        return 'A' <= c && c <= 'Z' || 'a' <= c && c <= 'z';
    }
};
