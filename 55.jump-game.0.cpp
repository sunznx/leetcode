// CreateTime: 2019-11-23 01:14:37
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int leaves = 0;
        for (int i = 0; i < nums.size()-1; i++) {
            leaves = max(nums[i], leaves-1);
            if (leaves <= 0) {
                return false;
            }
        }
        return true;
    }
};
