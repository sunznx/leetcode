// CreateTime: 2019-10-27 21:36:10
class Solution {
public:
    vector<string> m;

    void init() {
        m = vector<string>(28);
        m[0] = "Zero";
        m[1] = "One";
        m[2] = "Two";
        m[3] = "Three";
        m[4] = "Four";
        m[5] = "Five";
        m[6] = "Six";
        m[7] = "Seven";
        m[8] = "Eight";
        m[9] = "Nine";
        m[10] = "Ten";
        m[11] = "Eleven";
        m[12] = "Twelve";
        m[13] = "Thirteen";
        m[14] = "Fourteen";
        m[15] = "Fifteen";
        m[16] = "Sixteen";
        m[17] = "Seventeen";
        m[18] = "Eighteen";
        m[19] = "Nineteen";
        m[20] = "Twenty";
        m[21] = "Thirty";
        m[22] = "Forty";
        m[23] = "Fifty";
        m[24] = "Sixty";
        m[25] = "Seventy";
        m[26] = "Eighty";
        m[27] = "Ninety";
    }

    string numberToWords(int num) {
        init();

        if (0 <= num && num <= 20) {
            return m[num];
        }

        int billion = 0;
        int million = 0;
        int thousand = 0;
        int digit = 0;

        thousand = num % (int)1e6 / 1e3;
        million = num % (int)1e9 / 1e6;
        billion = num % (unsigned long long)1e12 / 1e9;
        digit = num % (int)1e3;

        string res = "";

        if (billion > 0) {
            appendStr(res, numberToWordsHelper(billion) + " Billion");
        }
        if (million > 0) {
            appendStr(res, numberToWordsHelper(million) + " Million");
        }

        if (thousand > 0) {
            appendStr(res, numberToWordsHelper(thousand) + " Thousand");
        }

        if (digit > 0) {
            appendStr(res, numberToWordsHelper(digit));
        }

        return res;
    }

    string numberToWordsHelper(int num) {
        int hundred = num / 100;
        int ten = num / 10 % 10;
        int digit = num % 10;

        string res = "";
        if (hundred > 0) {
            appendStr(res, m[hundred] + " Hundred");
        }

        if (ten > 0 && ten == 1) {
            appendStr(res, m[ten*10+digit]);
        } else {
            if (ten > 1) {
                appendStr(res, m[ten+18]);
            }

            if (digit) {
                appendStr(res, m[digit]);
            }
        }
        return res;
    }

    inline void appendStr(string &s, string substr) {
        if (s.size()) {
            s = s + " ";
        }

        s += substr;
    }
};

