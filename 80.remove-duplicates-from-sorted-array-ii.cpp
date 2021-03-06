// CreateTime: 2021-04-06 00:50:30
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for (int j = 1; j < nums.size(); j++) {
            if (nums[j] != nums[i] || (i == 0 || nums[i] != nums[i-1])) {
                nums[++i] = nums[j];
            }
        }
        return i+1;
    }
};