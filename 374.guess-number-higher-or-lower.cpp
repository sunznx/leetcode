// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int L = 1;
        int R = n;

        while (L <= R) {
            long mid = (R - L) / 2 + L;

            int res = guess(mid);

            if (res == 0) {
                return mid;
            } else if (res == 1) {
                L = mid + 1;
            } else if (res == -1) {
                R = mid - 1;
            }
        }

        return 0;
    }
};
