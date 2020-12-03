// CreateTime: 2020-12-03 23:38:43
class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int l = 1;
        int r = m * n;

        while (l < r) {
            int x = (l+r) / 2;

            if (check(x, m, n) - k >= 0) {
                r = x;
            } else {
                l = x+1;
            }
        }
        return l;
    }

    // 计算 <= x 的数有多少个
    int check(int x, int m, int n) {
        int count = 0;
        for (int i = 1; i <= m; i++) {
            count += min(x/i, n);
        }
        return count;
    }
};
