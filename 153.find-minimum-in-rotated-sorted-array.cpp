// CreateTime: 2021-04-08 08:44:12
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size()-1;
        return findMin(nums, l, r);
    }

    int findMin(vector<int>& nums, int l, int r) {
        if (l == r) {
            return nums[l];
        }

        int m = (l+r) / 2;
        if (nums[m] > nums[r]) {
            return findMin(nums, m+1, r);
        }
        return findMin(nums, l, m);
    }
};
