class Solution {
public:
    int integerBreak(int n) {
        if (n == 2) {
            return 1;
        }
        if (n == 3) {
            return 2;
        }

        int a = n / 3;
        int b = n % 3;
        if (b == 0) {
            return pow(3, a);
        }
        if (b == 1) {
            return pow(3, a-1) * 4;
        }
        return pow(3, a-1) * 6;
    }
};
