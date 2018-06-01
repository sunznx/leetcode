class Solution {
public:
    string convertToTitle(int n) {
        string res = "";

        n = n - 1;
        while (n != -1) {
            int mod = n % 26;
            n = n / 26 - 1;
            res += ('A' + mod);
        }

        reverse(res.begin(), res.end());

        return res;

    }
};
