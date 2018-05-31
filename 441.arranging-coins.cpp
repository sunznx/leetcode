class Solution {
public:
    int arrangeCoins(int n) {
        int L = 1;
        int R = n;

        while (L <= R) {
            long mid = (R - L) / 2 + L;
            long sum = (1 + mid) * mid / 2;
            long sum2 = (1 + (mid + 1)) * (mid+1) / 2;

            if (sum == n) {
                return mid;
            } else if (sum < n && sum2 > n) {
                return mid;
            } else if (sum < n) {
                L = mid + 1;
            } else if (sum > n) {
                R = mid - 1;
            }
        }

        return 0;
    }
};
