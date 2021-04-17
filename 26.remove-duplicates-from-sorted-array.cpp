// CreateTime: 2021-04-18 00:57:56
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int s = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0 || nums[i] != nums[i-1]) {
                nums[s] = nums[i];
                s++;
            }
        }
        return s;
    }
};
