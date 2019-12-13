// CreateTime: 2019-12-13 20:52:51
class Solution {
public:
    bool isArmstrong(int N) {
        int n = N;
        int c = cnt(n);
        int ans = 0;
        while (n) {
            int m = n % 10;
            n = n / 10;
            ans += pow(m, c);
        }
        return ans == N;
    }

    int cnt(int N) {
        int ans = 0;
        while (N) {
            N = N / 10;
            ans += 1;
        }
        return ans;
    }
};
