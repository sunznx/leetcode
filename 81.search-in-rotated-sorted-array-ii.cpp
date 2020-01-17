// CreateTime: 2020-01-18 00:52:39
class Solution {
  public:
    bool search(vector<int>& nums, int target) {
        return search(nums, 0, nums.size()-1, target);
    }

    bool search(vector<int>& nums, int l, int r, int target) {
        if (l > r) {
            return false;
        }

        if (l == r) {
            if (target == nums[l]) {
                return true;
            }
            return false;
        }

        if (nums[l] == nums[r]) {
            if (target == nums[l]) {
                return true;
            }
            return search(nums, l+1, r-1, target);
        }

        if (nums[l] > nums[r]) {
            int m = (l+r) / 2;
            return search(nums, l, m, target) || search(nums, m+1, r, target);
        } else {
            while (l < r) {
                int m = (l+r) / 2;
                if (nums[m] < target) {
                    l = m+1;
                } else {
                    r = m;
                }
            }
            return nums[l] == target;
        }

        return false;
    }
};
