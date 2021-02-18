// CreateTime: 2021-02-07 02:44:07
class Solution {
public:
    bool check(vector<int>& nums) {
        int len = nums.size();
        int maxn = 0;
        int sub = 1;
        for (int i = 1; i < len*2; i++) {
            auto x = nums[i%len];
            auto pre = nums[(i-1)%len];

            if (x >= pre) {
                sub++;
            } else {
                sub = 1;
            }
            maxn = max(maxn, sub);
        }

        return maxn >= len;
    }
};