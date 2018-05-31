// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int L = 1;
        int R = n;

        int res;

        while (L <= R) {
            long mid = (R - L) / 2 + L;

            if (isBadVersion(mid)) {
                res = mid;
                R = mid-1;
            } else {
                L = mid + 1;
            }
        }

        return res;
    }
};
