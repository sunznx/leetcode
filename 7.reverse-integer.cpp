class Solution {
public:
    int reverse(int x) {
        if (x == -2147483648) {
            return 0;
        }

        bool needRevert = false;
        if (x < 0) {
            x = -x;
            needRevert = true;
        }

        int res = 0;

        int count = 0;
        while (x) {
            count++;

            int t = x % 10;
            x = x / 10;

            if (count == 10) {
                if ( (res > 214748364) || (!needRevert && res == 214748364 && t >= 8) || (needRevert && res == 214748364 && t >= 8)) {
                    return 0;
                }
            }

            res = res * 10 + t;
        }

        if (needRevert) {
            res = -res;
        }

        return res;
    }
};
