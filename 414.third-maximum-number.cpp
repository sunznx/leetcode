class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int len = nums.size();
        if (len == 2) {
            return max(nums[0], nums[1]);
        }
        if (len == 1) {
            return nums[0];
        }

        sort(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end());

        int count = 1;
        for (int i = 1; i < len; i++) {
            if (nums[i] != nums[i-1]) {
                count++;
            }
            if (count == 3) {
                return nums[i];
            }
        }

        return nums[0];
    }
};
