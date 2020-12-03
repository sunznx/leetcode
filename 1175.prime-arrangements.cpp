// CreateTime: 2020-12-03 17:09:38
class Solution {
public:
    int numPrimeArrangements(int n) {
        const int MOD = 1e9 + 7;

        vector<bool> isPrime(n+2, true);
        isPrime[0] = false;
        isPrime[1] = false;

        int primeCount = 0;
        for (int i = 2; i <= n; i++) {
            if (isPrime[i]) {
                for (int j = 2; j <= n/i; j++) {
                    isPrime[i*j] = false;
                }
                primeCount++;
            }
        }

        int nonPrimeCount = n-primeCount;

        long long ans = 1;
        for (int i = 1; i <= primeCount; i++) {
            ans = (ans * i) % MOD;
        }
        for (int i = 1; i <= nonPrimeCount; i++) {
            ans = (ans * i) % MOD;
        }
        return ans;
    }
};
