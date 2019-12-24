// CreateTime: 2019-12-24 15:54:54
class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        int len = nums.size();
        int l = s1(nums, target);
        int r = s2(nums, target);

        if (nums[l] != target || nums[r] != target) {
            return false;
        }

        int sz = (r-l)+1;
        return sz > len/2;
    }
    
    int s1(vector<int> &nums, int target) {
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
        
        return r;
    }
    
    int s2(vector<int> &nums, int target) {
        int l = 0;
        int r = nums.size()-1;
        
        while (l < r) {
            int m = (l+r+1) / 2;
            
            if (nums[m] <= target) {
                l = m;
            } else if (nums[m] > target) {
                r = m-1;
            }
        }
        
        return l;
    }
};
