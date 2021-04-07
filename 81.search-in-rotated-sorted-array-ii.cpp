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

        int m = (l+r) / 2;
        if (nums[m] == nums[l]) {
            return search(nums, l, m, target) || search(nums, m+1, r, target);
        }
        if (nums[m] == nums[r]) {
            return search(nums, l, m-1, target) || search(nums, m, r, target);
        }

        if (nums[l] == nums[r]) {
            if (target == nums[l]) {
                return true;
            }
            return search(nums, l+1, r-1, target);
        }

        if (nums[m] > nums[l]) {
            if (target > nums[m]) {
                return search(nums, m+1, r, target);
            }

            return search(nums, l, m, target) || search(nums, m+1, r, target);
        }

        if (target > nums[m]) {
            return search(nums, l, m, target) || search(nums, m+1, r, target);
        }
        return search(nums, l, m, target);
    }
};
