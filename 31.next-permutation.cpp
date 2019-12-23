// CreateTime: 2019-12-23 21:38:55
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();

        for (int i = len-1; i >= 1; i--) {
            if (nums[i-1] < nums[i]) {
                int k = i+1;
                while (k < len && nums[k] > nums[i-1]) {
                    k++;
                }
                swap(nums[k-1], nums[i-1]);
                reverse(nums.begin()+i, nums.end());
                return;
            }
        }

        reverse(nums.begin(), nums.end());
    }
};
