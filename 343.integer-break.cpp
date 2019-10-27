class Solution {
public:
    int integerBreak(int n) {
        if (n == 0 || n == 1 || n == 2) {
            return 1;
        }
        if (n == 3) {
            return 2;
        }
        if (n == 4) {
            return 4;
        }

        int mod = n % 3;
        if (mod == 0) {
            return pow(3, n/3);
        } else if (mod == 1) {
            return pow(3, (n-3) / 3) * 4;
        }
        return pow(3, (n-3) / 3) * 6;
    }
};
