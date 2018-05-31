class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int len = nums.size();

        int last_idx = -1;    // find the last index for the non zero
        for (int i = 0; i < len; i++) {
            if (nums[i] != 0) {
                int t = nums[i];
                nums[i] = nums[last_idx+1];
                nums[last_idx+1] = t;
                last_idx = last_idx + 1;
            }
        }
    }
};
