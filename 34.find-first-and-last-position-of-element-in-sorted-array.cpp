class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        int len = nums.size();
        if (len == 0) {
            return res;
        }

        int l = 0;
        int r = nums.size()-1;
        while (l <= r) {
            int m = (l+r) / 2;
            if (nums[m] == target) {

                int x = m;
                int y = m;

                while (x >= 0 && nums[x] == target) {
                    x -= 1;
                };
                while (y <= nums.size()-1 && nums[y] == target) {
                    y += 1;
                }
                res[0] = x+1;
                res[1] = y-1;
                break;
            } else if (nums[m] > target) {
                r = m-1;
            } else {
                l = m+1;
            }
        }

        return res;
    }
};
