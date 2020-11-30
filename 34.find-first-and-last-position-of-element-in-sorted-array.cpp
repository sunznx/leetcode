// CreateTime: 2020-12-01 07:34:52
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2, -1);
        ans[0] = findL(nums, target);
        ans[1] = findR(nums, target);
        return ans;
    }

    int findL(vector<int>& nums, int target) {
        if (nums.size() == 0) {
            return -1;
        }

        int l = 0;
        int r = nums.size()-1;

        while (l < r) {
            int m = (l+r) / 2;

            if (nums[m] < target) {
                l = m+1;
            } else if (nums[m] >= target) {
                r = m;
            }
        }

        if (nums[l] == target) {
            return l;
        }
        return -1;
    }

    int findR(vector<int>& nums, int target) {
        if (nums.size() == 0) {
            return -1;
        }

        int l = 0;
        int r = nums.size()-1;

        while (l < r) {
            int m = (l+r+1) / 2;

            if (nums[m] <= target) {
                l = m;
            } else if (nums[m] > target) {
                r = m-1;
            }
        }

        if (nums[l] == target) {
            return l;
        }
        return -1;
    }
};
