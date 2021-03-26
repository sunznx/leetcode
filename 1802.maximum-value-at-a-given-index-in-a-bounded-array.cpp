// CreateTime: 2021-03-27 03:48:56
class Solution {
public:
    typedef long long LL;

    int maxValue(int n, int index, int maxSum) {
        int l = 1;
        int r = maxSum;

        while (l < r) {
            int m = (l+r+1) / 2;
            if (check(n, index, maxSum, m)) {
                l = m;
            } else {
                r = m-1;
            }
        }
        return r;
    }

    bool check(LL n, LL index, LL maxSum, LL m) {
        int cntL = index;
        int cntR = (n-1-index);

        LL min1 = 0;
        LL min2 = 0;
        if (m-cntL <= 0) {
            min1 = (1+(m-1)) * (m-1) / 2 + cntL - (m-1);
        } else {
            min1 = ((m-cntL)+(m-1)) * cntL / 2;
        }
        if (m-cntR <= 0) {
            min2 = (1+(m-1)) * (m-1) / 2 + cntR - (m-1);
        } else {
            min2 = ((m-cntR)+(m-1)) * cntR / 2;
        }

        LL minVal = min1 + min2 + m;
        LL maxVal = ((m+cntL)+(m+1)) * cntL / 2 + ((m+cntR)+(m+1)) * cntR / 2 + m;

        return minVal <= maxSum && maxSum <= maxVal || maxVal <= maxSum;
    }
};
