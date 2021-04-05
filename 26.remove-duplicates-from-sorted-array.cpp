// CreateTime: 2021-04-06 00:56:50
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0;
        while (k < nums.size()) {
            if (k > 0 && nums[k] == nums[k-1]) {
                nums.erase(nums.begin()+k);
            } else {
                k++;
            }
        }
        return nums.size();
    }
};

