// CreateTime: 2021-01-27 16:07:26
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            auto &x = nums[i];

            while (x > 0 && x <= len && nums[x-1] != x) {
                swap(nums[x-1], x);
            }
        }

        for (int i = 0; i < len; i++) {
            auto x = nums[i];
            if (x != i+1) {
                return i+1;
            }
        }
        return len+1;
    }
};
