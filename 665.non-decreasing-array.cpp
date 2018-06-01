class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int len = nums.size();
        if (len <= 2) {
            return true;
        }

        bool has_chance = true;
        int max1;
        int max2;

        if (nums[0] <= nums[1]) {
            max1 = nums[1];
            max2 = nums[0];
        } else {
            max1 = nums[1];
            max2 = nums[1];
            has_chance = false;
        }

        for (int i = 2; i < len; i++) {
            if (nums[i] >= max1) {
                max2 = max1;
                max1 = nums[i];
            } else if (nums[i] < max2) {
                if (has_chance) {
                    has_chance = false;
                } else {
                    return false;
                }
            } else if (nums[i] >= max2 && nums[i] < max1) {
                if (has_chance) {
                    has_chance = false;
                } else {
                    return false;
                }
                max1 = nums[i];
            }
        }

        return true;
    }
};
