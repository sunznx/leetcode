// CreateTime: 2021-04-07 20:26:26
class Solution {
public:
    int search(vector<int>& nums, int target) {
        return search(nums, 0, nums.size()-1, target);
    }

    int search(vector<int>& nums, int l, int r, int target) {
        if (l > r) {
            return -1;
        }

        if (l == r) {
            if (target == nums[l]) {
                return l;
            }
            return -1;
        }

        int m = (l+r) / 2;
        if (nums[m] >= nums[l]) {
            if (target > nums[m]) {
                return search(nums, m+1, r, target);
            }

            auto s1 = search(nums, l, m, target);
            if (s1 != -1) {
                return s1;
            }
            return search(nums, m+1, r, target);
        }

        if (target > nums[m]) {
            auto s1 = search(nums, l, m, target);
            if (s1 != -1) {
                return s1;
            }
            return search(nums, m+1, r, target);
        }

        return search(nums, l, m, target);
    }
};
