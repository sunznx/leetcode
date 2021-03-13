// CreateTime: 2020-01-09 07:56:26
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int times = 0;
        int res;
        
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            if (times == 0) {
                res = nums[i];
                times++;
            } else if (res == nums[i]) {
                times++;
            } else {
                times--;
            }
        }
        
        return res;
    }
};
