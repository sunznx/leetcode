// CreateTime: 2019-10-28 14:51:38
class Solution {
public:
    map<int, string> m;

    void init() {
        m[0]  = "";
        m[1]  = "I";
        m[2]  = "II";
        m[3]  = "III";
        m[4]  = "IV";
        m[5]  = "V";
        m[6]  = "VI";
        m[7]  = "VII";
        m[8]  = "VIII";
        m[9]  = "IX";
        m[10] = "X";
        m[40] = "XL";
        m[50] = "L";
        m[90] = "XC";
        m[100] = "C";
        m[400] = "CD";
        m[500] = "D";
        m[900] = "CM";
        m[1000] = "M";
    }

    string intToRoman(int num) {
        init();

        int thousand = num / 1000;
        int hundred = (num - thousand * 1000) / 100;
        int ten = (num - thousand * 1000 - 100 * hundred) / 10;
        int digit = num % 10;

        string res = "";
        if (thousand) {
            res += repeatStr(m[1000], thousand);
        }

        if (1 <= hundred && hundred <= 3) {
            res += repeatStr(m[100], hundred);
        } else if (hundred == 4) {
            res += repeatStr(m[400], 1);
        } else if (hundred == 5) {
            res += repeatStr(m[500], 1);
        } else if (hundred == 9) {
            res += repeatStr(m[900], 1);
        } else if (6 <= hundred && hundred <= 8) {
            res += repeatStr(m[500], 1) + repeatStr(m[100], hundred-5);
        }

        if (1 <= ten && ten <= 3) {
            res += repeatStr(m[10], ten);
        } else if (ten == 4) {
            res += repeatStr(m[40], 1);
        } else if (ten == 5) {
            res += repeatStr(m[50], 1);
        } else if (ten == 9) {
            res += repeatStr(m[90], 1);
        } else if (6 <= ten && ten <= 8) {
            res += repeatStr(m[50], 1) + repeatStr(m[10], ten-5);
        }

        res += m[digit];

        return res;
    }

    inline string repeatStr(string s, int times) {
        string t = s;
        for (int i = 1; i < times; i++) {
            s += t;
        }
        return s;
    }
};
