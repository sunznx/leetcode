// CreateTime: 2020-12-03 15:46:06
class Solution {
public:
    bool isPrime(int n) {
        if (n <= 1) {
            return false;
        }

        if (n == 2) {
            return true;
        }

        if (n % 2 == 0) {
            return false;
        }

        for (int i = 3; i*i <= n; i+=2) {
            if (n % i == 0) {
                return false;
            }
        }
        
        return true;
    }

    int countBit(int n) {
        int ans = 0;
        
        while (n != 0) {
            n = (n & (n-1));
            ans += 1;
        }

        return ans;
    }

    int countPrimeSetBits(int l, int r) {
        int ans = 0;
        for (int i = l; i <= r; i++) {
            if (isPrime(countBit(i))) {
                ans += 1;
            }
        }
        
        return ans;
    }
};
