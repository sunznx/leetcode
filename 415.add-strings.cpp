class Solution {
public:
    string addStrings(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        int len1 = a.size();
        int len2 = b.size();
        int carry = 0;
        string res = "";

        int i = 0;
        int j = 0;

        while ( !(i == len1 && j == len2 && carry == 0) ) {
            int val;
            int val1 = 0;
            int val2 = 0;
            if (i == len1 && j == len2) {

            } else if (i == len1) {
                val2 = b[j++] - '0';
            } else if (j == len2) {
                val1 = a[i++] - '0';
            } else {
                val1 = a[i++] - '0';
                val2 = b[j++] - '0';
            }

            val = val1 + val2 + carry;

            carry = val / 10;
            val = val % 10;
            res += val + '0';
        }

        reverse(res.begin(), res.end());

        return res;
    }
};
