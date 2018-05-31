class Solution {
public:
    int mySqrt(int x) {
        int L = 1;
        int R = x;

        while (L <= R) {
            long mid = (R - L) / 2 + L;

            long sum = mid * mid;
            long sum2 = (mid+1) * (mid+1);

            if (sum == x) {
                return mid;
            } else if (sum < x && x < sum2) {
                return mid;
            } else if (sum < x) {
                L = mid + 1;
            } else if (sum > x) {
                R = mid - 1;
            }
        }

        return 0;
    }
};
