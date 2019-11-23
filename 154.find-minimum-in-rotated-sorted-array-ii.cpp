// CreateTime: 2019-11-23 17:58:46
class Solution {
public:
    int res;
    int findMin(vector<int>& nums) {
        res = nums[0];
        findMinHelper(nums, 0, nums.size()-1);
        return res;
    }

    void findMinHelper(vector<int>& nums, int l, int r) {
        res = min(res, nums[l]);
        while (l < r) {
            int m = (l+r+1) / 2;

            if (nums[l] == nums[r]) {
                findMinHelper(nums, l, m-1);
                findMinHelper(nums, m, r);
                return;
            }

            if (nums[m] < nums[l]) {
                res = min(res, nums[m]);
                r = m-1;
            } else {
                l = m;
            }
        }
    }
};
