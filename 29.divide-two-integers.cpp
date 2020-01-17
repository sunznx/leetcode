// CreateTime: 2020-01-18 00:08:20
class Solution {
  public:
    const int MAX_INT = 2147483647;
    const int MIN_INT = -2147483648;

    bool sign = false;

    int divide(int dividend, int divisor) {
        if (divisor == 1) {
            return dividend;
        }

        if (divisor == -1) {
            if (dividend == MIN_INT) {
                return MAX_INT;
            }
            return -dividend;
        }

        if (dividend == 0) {
            return 0;
        }

        if (dividend < 0 && divisor < 0 ||  dividend > 0 && divisor > 0) {
            sign = false;
        } else {
            sign = true;
        }

        long d1 = abs((long)dividend);
        long d2 = abs((long)divisor);

        int res = 0;
        int b = 1;
        while (d1 && d2) {
            if (d1 >= (d2 << 1)) {
                d1 -= (d2 << 1);
                d2 = (d2 << 1);
                res += (b << 1);
                b = (b << 1);
            } else if (d1 >= d2) {
                d1 -= d2;
                res += b;
            } else {
                d2 = (d2 >> 1);
                b = (b >> 1);
            }
        }

        if (sign) {
            return -res;
        }
        return res;
    }
};
