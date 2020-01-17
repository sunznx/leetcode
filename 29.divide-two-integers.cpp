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

        if (sign) {
            return -divide(abs((long)dividend), abs((long)divisor));
        }

        return divide(abs((long)dividend), abs((long)divisor));
    }

    int divide(long dividend, long divisor) {
        int res = 0;
        int b = 1;
        while (dividend && divisor) {
            if (dividend >= (divisor << 1)) {
                dividend -= (divisor << 1);
                divisor = (divisor << 1);
                res += (b << 1);
                b = (b << 1);
            } else if (dividend >= divisor) {
                dividend -= divisor;
                res += b;
            } else {
                divisor = (divisor >> 1);
                b = (b >> 1);
            }
        }
        return res;
    }
};
