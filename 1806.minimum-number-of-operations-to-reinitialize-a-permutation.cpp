// CreateTime: 2021-03-28 10:40:46
class Solution {
public:
    int reinitializePermutation(int n) {
        int ans = 1;

        int x = n/2;
        while (x != 1) {
            if (x % 2 == 0) {
                x = x / 2;
            } else {
                x = n / 2 + (x-1) / 2;
            }
            ans++;
        }
        return ans;
    }
};