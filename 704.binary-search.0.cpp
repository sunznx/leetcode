// CreateTime: 2020-11-24 07:45:19
class Solution {
public:
    int search(vector<int>& nums, int target) {
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
};
