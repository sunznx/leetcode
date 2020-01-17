// CreateTime: 2020-01-18 00:59:05
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

        if (nums[l] > nums[r]) {
            int m = (l+r) / 2;
            auto ll = search(nums, l, m, target);
            auto rr = search(nums, m+1, r, target);

            if (ll == -1 && rr == -1) {
                return -1;
            } else if (ll == -1) {
                return rr;
            } else if (rr == -1) {
                return ll;
            } else {
                return -1;
            }
        } else {
            while (l < r) {
                int m = (l+r) / 2;
                if (nums[m] < target) {
                    l = m+1;
                } else {
                    r = m;
                }
            }
            if (nums[l] == target) {
                return l;
            }
            return -1;
        }

        return -1;
    }
};
