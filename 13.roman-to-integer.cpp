class Solution {
public:
    int romanToInt(string s) {
        int len = s.size();
        if (len == 0) {
            return 0;
        }

        vector<int> strmap(26, 0);
        strmap['I' - 'A'] = 1;
        strmap['V' - 'A'] = 5;
        strmap['X' - 'A'] = 10;
        strmap['L' - 'A'] = 50;
        strmap['C' - 'A'] = 100;
        strmap['D' - 'A'] = 500;
        strmap['M' - 'A'] = 1000;

        int res = 0;
        int from = 0;
        for (int i = 1; i < len; i++) {
            int vCur = calc(s, strmap, i);
            int vPrev = calc(s, strmap, i-1);

            if (vCur < vPrev) {
                res += calcInterval(s, strmap, from, i-1);
                from = i;
            }
        }

        return calcLastInterval(s, strmap, from, len-1, res);
    }

    int calc(string s, vector<int> strmap, int i) {
        return strmap[s[i] - 'A'];
    }

    int calcInterval(string s, vector<int> strmap, int l, int r) {
        int res = 0;
        int vr = calc(s, strmap, r);
        for (int i = l; i <= r-1; i++) {
            int vi = calc(s, strmap, i);
            if (vi == vr) {
                res += vi;
            } else {
                res -= vi;
            }
        }

        return res + vr;
    }

    int calcLastInterval(string s, vector<int> strmap, int l, int r, int res) {
        int tmpRes = calcInterval(s, strmap, l, r);
        if (l == 0) {
            return tmpRes;
        } else {
            int vCur = calc(s, strmap, l);
            int vPrev = calc(s, strmap, l-1);
            if (vCur > vPrev) {
                return tmpRes - res;
            } else {
                return tmpRes + res;
            }
        }
    }
};
