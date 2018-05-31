class Solution {
public:
    set<int> S;
    bool isHappy(int n) {
        int a[10];
        for (int i = 0; i < 10; i++) {
            a[i] = i*i;
        }
        int t;
        long long sum = 0;
        while (n != 0) {
            t = n % 10;
            n = n / 10;
            sum += t * t;
        }
        if (sum == 1) {
            return 1;
        } else {
            if (S.find(sum) != S.end()) {
                return 0;
            }
            S.insert(sum);
            return isHappy(sum);
        }
    }
};
