class Solution {
public:
    int rotatedDigits(int n) {
        int res = 0;
        for (int i = 1; i <= n; i++) {
            int tmp = i;
            int after = 0;

            int carry = 1;
            int ok = 1;
            while (tmp != 0) {
                int mod = tmp % 10;
                tmp = tmp / 10;

                int v = valid(mod);
                if (v == -1) {
                    ok = 0;
                    break;
                }
                after = after + v * carry;
                carry = carry * 10;
            }

            if (after != i && ok == 1) {
                res++;
            }
        }

        return res;
    }

    int valid(int n) {
        if (n == 2) {
            return 5;
        }
        if (n == 5) {
            return 2;
        }
        if (n == 6) {
            return 9;
        }
        if (n == 9) {
            return 6;
        }

        if (n == 0 || n == 1 || n == 8) {
            return n;
        }

        return -1;
    }
};
