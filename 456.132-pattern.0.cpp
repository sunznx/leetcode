// CreateTime: 2019-12-04 10:41:47
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int len = nums.size();
        if (len < 3) {
            return false;
        }

        int minl = nums[0];
        for (int i = 0; i < len; i++) {
            if (nums[i] > minl) {
                for (int j = i+1; j < len; j++) {
                    if (nums[j] < nums[i] && nums[j] > minl) {
                        return true;
                    }
                }
            }
            minl = min(minl, nums[i]);
        }
        return false;
    }
};
