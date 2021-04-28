class Solution {
public:

    typedef long long LL;

    bool judgeSquareSum(int c) {
        for (LL i = 0; i*i <= c; i++) {
            int target = c - i * i;
            if (check(target)) {
                return true;
            }
        }

        return false;
    }

    bool check(int n) {
        if (n == 1 || n == 0) {
            return true;
        }

        LL i1 = (LL)sqrt(n);
        LL i2 = i1 - 1;
        LL i3 = i1 + 1;

        if (i1 * i1 == n) {
            return true;
        }
        if (i2 * i2 == n) {
            return true;
        }
        if (i3 * i3 == n) {
            return true;
        }

        return false;
    }
};
