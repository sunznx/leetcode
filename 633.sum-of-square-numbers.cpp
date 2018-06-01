class Solution {
public:
    bool judgeSquareSum(int c) {
        for (int i = 0; i*i <= c/2; i++) {
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

        int i1 = (int)sqrt(n);
        int i2 = i1 - 1;
        int i3 = i1 + 1;

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
