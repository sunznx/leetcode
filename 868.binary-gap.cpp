// CreateTime: 2019-12-14 16:27:49
class Solution {
public:
    int binaryGap(int N) {
        int ans = 0;
        int k = 1;
        int prev = 0;
        while (N) {
            int m = N % 2;
            N = N / 2;
            
            if (m == 1) {
                if (prev) {
                    ans = max(ans, k-prev);
                }
                prev = k;
            }
            k++;
        }
        return ans;
    }
};
