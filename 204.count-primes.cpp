// CreateTime: 2020-12-03 15:32:01
class Solution {
public:
    int countPrimes(int n) {
        vector<bool> isPrime(n+2, true);

        isPrime[0] = false;
        isPrime[1] = false;

        int ans = 0;
        for (int i = 2; i <= n-1; i++) {
            if (isPrime[i]) {
                for (int j = 2; j <= (n-1)/i; j++) {
                    isPrime[i*j] = false;
                }
                ans++;
            }
        }
        return ans;
    }
};
