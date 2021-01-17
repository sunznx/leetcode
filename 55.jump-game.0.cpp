// CreateTime: 2021-01-17 18:24:36
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len = nums.size();
        vector<int> f(len);

        for (int i = 0; i < len-1; i++) {
            if (i == 0) {
                f[i] = nums[i];
            } else {
                f[i] = max(nums[i], f[i-1]-1);
            }

            if (f[i] <= 0) {
                return false;
            }
        }
        return true;
    }
};
