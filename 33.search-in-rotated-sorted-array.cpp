class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        if (len == 0) {
            return -1;
        }

        int idx = findPivot(nums);

        int l = 0;
        int r = idx;

        if (! (nums[0] <= target && target <= nums[idx])) {
            l = idx+1;
            r = len-1;
        }

        while (l <= r) {
            int m = (l+r) / 2;
            if (target == nums[m]) {
                return m;
            }
            if (target > nums[m]) {
                l = m+1;
            }
            if (target < nums[m]) {
                r = m-1;
            }
        }

        return -1;
    }

    int findPivot(vector<int>& nums) {
        int len = nums.size();
        int res = len-1;
        for (int i = 1; i < len; i++) {
            if (nums[i] < nums[i-1]) {
                return i-1;
            }
        }
        return res;
    }
};
