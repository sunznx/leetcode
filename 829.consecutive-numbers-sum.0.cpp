class Solution {
public:
    int consecutiveNumbersSum(int N) {
        int ans = 0;
        for (int len = 1; len * len/2 < N; len++) {
            int l = 1;
            int r = N;
            while (l <= r) {
                int mid = (l+r)/2;
                unsigned long long v = sumLen(mid, len);
                if (v == N) {
                    ans += 1;
                    break;
                } else if (v > N) {
                    r = mid-1;
                } else {
                    l = mid+1;
                }
            }
        }
        return ans;
    }

    unsigned long long sumLen(int idx, int len) {
        unsigned long long ans = (unsigned long long)(idx + idx + len-1) * len;
        return ans / 2;
    }
};


