// CreateTime: 2021-04-30 10:52:00
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < 32; i++) {
            int m = 0;
            for (auto &x: nums) {
                if ((x & (1<<i)) != 0) {
                    m++;
                }                
            }
            
            if (m % 3 != 0) {
                ans += (1<<i);
            }
        }

        return ans;
    }
};
