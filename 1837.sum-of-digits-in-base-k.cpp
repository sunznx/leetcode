// CreateTime: 2021-04-25 10:30:29
class Solution {
public:
    int sumBase(int n, int k) {
        int ans = 0;
        while (n) {
            int mod = n % k;
            n = n / k;
            ans += mod;
        }
        return ans;
    }
};