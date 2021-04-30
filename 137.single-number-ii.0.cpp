// CreateTime: 2021-04-30 10:52:00
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> m(32);

        for (auto &x: nums) {
            for (int i = 0; i < 32; i++) {
                if ((x & (1<<i)) != 0) {
                    m[i]++;
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < 32; i++) {
            if (m[i] % 3 != 0) {
                ans += (1<<i);
            }
        }
        return ans;
    }
};
