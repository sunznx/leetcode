// CreateTime: 2020-12-03 17:18:19
class Solution {
public:
    int primePalindrome(int N) {
        while (true) {
            if (isPalindrome(N) && isPrime(N)) {
                return N;
            }
            N = getNextPalindrome(N);
        }
        return -1;
    }

    bool isPalindrome(int n) {
        vector<int> bits;
        while (n != 0) {
            auto m = n % 10;
            bits.insert(bits.begin(), m);
            n = n / 10;
        }

        for (int i = 0; i < bits.size()-1-i; i++) {
            auto l = bits[i];
            auto r = bits[bits.size()-1-i];
            if (l != r) {
                return false;
            }
        }
        return true;
    }

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

        for (int i = 3; i <= n/i; i+=2) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }

    int generateFromBits(vector<int> &bits) {
        int len = bits.size();
        if (len % 2 == 0) {
            auto ans = 0;
            for (int i = 0; i <= len/2-1; i++) {
                ans = ans * 10 + bits[i];
            }
            for (int i = len/2-1; i >= 0; i--) {
                ans = ans * 10 + bits[i];
            }
            return ans;
        }

        auto ans = 0;
        for (int i = 0; i <= len/2-1; i++) {
            ans = ans * 10 + bits[i];
        }
        ans = ans * 10 + bits[len/2];
        for (int i = len/2-1; i >= 0; i--) {
            ans = ans * 10 + bits[i];
        }
        return ans;
    }

    int getNextPalindrome(int n) {
        int old = n;

        vector<int> bits;
        while (n != 0) {
            auto m = n % 10;
            bits.insert(bits.begin(), m);
            n = n / 10;
        }

        int len = bits.size();

        auto ans = generateFromBits(bits);
        if (ans > old) {
            return ans;
        }

        // 如果是 99 999 9999 99999 这种
        if (ans == pow(10, len)-1) {
            return pow(10, len)+1;
        }

        if (len % 2 == 0) {
            bits[len/2-1]++;
            return generateFromBits(bits);
        }

        bits[len/2]++;
        return generateFromBits(bits);
    }
};
