// CreateTime: 2019-12-31 11:13:48
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int res = 0;
        int v = 0;
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            if (i == 0 || nums[i] > nums[i-1]) {
                v += 1;
                res = max(res, v);
            } else {
                v = 1;
            }
        }
        
        return res;
    }
};
