// CreateTime: 2021-04-15 08:40:27
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int k = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (k <= 0) {
                return false;
            }
            k = max(k-1, nums[i]);
        }
        return true;
    }
};
