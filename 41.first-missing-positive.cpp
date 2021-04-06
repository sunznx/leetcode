// CreateTime: 2020-01-04 21:25:48
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            auto &x = nums[i];
            
            while (1 <= x && x <= nums.size() && nums[x-1] != x) {
                swap(nums[x-1], x);
            }
        }
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != i+1) {
                return i+1;
            }
        }
        return nums.size()+1;
    }
};
