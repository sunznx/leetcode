// CreateTime: 2019-12-05 16:44:27
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) {
            return "0";
        }

        string res = "";

        if (numerator < 0 || denominator < 0) {
            if (!(numerator < 0 && denominator < 0)) {
                res += "-";
            }
        }

        long long n1 = numerator;
        long long n2 = denominator;

        n1 = abs(n1);
        n2 = abs(n2);

        res += to_string(n1 / n2);
        long long mod = n1 % n2;
        if (mod == 0) {
            return res;
        }

        return res + "." + helper(mod, n2);
    }

    string helper(long long n, long long d) {
        unordered_map<long, int> m;

        int k = 0;
        string res = "";

        while (n != 0 && m.find(n) == m.end()) {
            m[n] = k++;
            res += to_string(n*10 / d);
            n = n*10 % d;
        }

        if (n == 0) {
            return res;
        }

        int s = m[n];
        return res.substr(0, s) + "(" + res.substr(s, k-s) + ")";
    }
};

