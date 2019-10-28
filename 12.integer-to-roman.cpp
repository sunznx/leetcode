class Solution {
public:
    string intToRoman(int num) {
        auto m = vector<vector<string>> (4, vector<string> (10));
        m[0][0] = "";
        m[0][1] = "I";
        m[0][2] = "II";
        m[0][3] = "III";
        m[0][4] = "IV";
        m[0][5] = "V";
        m[0][6] = "VI";
        m[0][7] = "VII";
        m[0][8] = "VIII";
        m[0][9] = "IX";

        m[1][0] = "";
        m[1][1] = "X";
        m[1][2] = "XX";
        m[1][3] = "XXX";
        m[1][4] = "XL";
        m[1][5] = "L";
        m[1][6] = "LX";
        m[1][7] = "LXX";
        m[1][8] = "LXXX";
        m[1][9] = "XC";

        m[2][0] = "";
        m[2][1] = "C";
        m[2][2] = "CC";
        m[2][3] = "CCC";
        m[2][4] = "CD";
        m[2][5] = "D";
        m[2][6] = "DC";
        m[2][7] = "DCC";
        m[2][8] = "DCCC";
        m[2][9] = "CM";

        m[3][0] = "";
        m[3][1] = "M";
        m[3][2] = "MM";
        m[3][3] = "MMM";

        int thousand = num / 1000;
        int hundred = num / 100 % 10;
        int ten = num / 10 % 10;
        int digit = num % 10;

        string res = "";
        res += m[3][thousand];
        res += m[2][hundred];
        res += m[1][ten];
        res += m[0][digit];
        return res;
    }
};
