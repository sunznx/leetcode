// CreateTime: 2019-11-28 15:49:41
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int len = nums.size();
        
        for (int i = 1; i < len; i++) {
            nums[i] += nums[i-1];
        }
        
        int l;
        int r;
        for (int i = 0; i < len; i++) {
            if (i == 0) {
                l = 0;
            } else {
                l = nums[i-1];
            }
            r = nums[len-1] - nums[i];
            
            if (l == r) {
                return i;
            }
        }

        return -1;
    }
};
