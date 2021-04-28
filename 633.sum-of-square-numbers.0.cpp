// CreateTime: 2021-04-28 18:38:39
class Solution {
public:
    typedef long long LL;

    bool judgeSquareSum(int c) {
        LL l = 0;
        LL r = (LL)sqrt(c);

        while (l <= r) {
            auto s = l*l + r*r;

            if (s == c) {
                return true;
            } else if (s > c) {
                r = r-1;
            } else {
                l = l+1;
            }
        }
        return false;
    }
};
