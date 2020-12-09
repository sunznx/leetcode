// CreateTime: 2020-12-10 03:38:24
class Solution {
public:
    int mySqrt(int x) {
        long long l = 0;
        long long r = x; 

        while (l < r) {
            long long mid = (l+r+1)/2;
            long long val = mid * mid;
            if (val <= x) {
                l = mid;
            } else if (val > x) {
                r = mid-1;
            }
        }
        return (int)l;
    }
};
