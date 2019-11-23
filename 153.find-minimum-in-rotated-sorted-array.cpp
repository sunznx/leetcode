// CreateTime: 2019-11-23 09:35:43
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size()-1;
        int res = nums[0];
        while (l < r) {
            int m = (l+r+1) / 2;
            if (nums[m] < nums[0]) {
                res = nums[m];
                r = m-1;
            } else {
                l = m;
            }
        }

        return res;
    }
};
