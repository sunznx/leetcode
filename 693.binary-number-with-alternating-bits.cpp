class Solution {
public:
    bool hasAlternatingBits(int n) {
        bool res = true;

        bool isOne = false;
        bool isFirst = true;
        while (n != 0) {
            int t = n % 2;
            n = n / 2;

            if (t == 1 && (isOne == false || isFirst == true)) {
                isOne = true;
                isFirst = false;
            } else if (t == 0 && (isOne == true || isFirst == true)) {
                isOne = false;
                isFirst = false;
            } else {
                return false;
            }
        }

        return res;
    }

    int lowbit(int x) {
        if (x == 0) {
            return 0;
        }

        return ((x) & (x-1));
    }
};
