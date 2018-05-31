class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int len = nums.size();

        int L = 0;
        int R = len-1;

        while (L <= R) {
            long mid = (R - L) / 2 + L;

            if (nums[mid] == target) {
                return mid;
            } else if (L == R) {
                if (target > nums[mid]) {
                    return mid + 1;
                } else {
                    return mid;
                }
            } else if (nums[mid] < target && nums[mid+1] > target) {
                return mid+1;
            } else if (nums[mid] < target) {
                L = mid + 1;
            } else if (nums[mid] > target) {
                R = mid - 1;
            }
        }

        return 0;
    }
};
