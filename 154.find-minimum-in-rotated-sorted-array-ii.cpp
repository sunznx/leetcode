// CreateTime: 2021-04-09 00:28:14
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size()-1;
        return findMin(nums, l, r);
    }

    int findMin(vector<int>& nums, int l, int r) {
        if (l > r) {
            return INT_MAX;
        }
        if (l == r) {
            return nums[l];
        }

        int m = (l+r) / 2;
        
        if (nums[m] == nums[r]) {
            return findMin(nums, l, r-1);
        }

        if (nums[m] > nums[r]) {
            return findMin(nums, m+1, r);
        }
        return findMin(nums, l, m);
    }
};
