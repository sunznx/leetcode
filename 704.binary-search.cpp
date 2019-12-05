// CreateTime: 2019-12-06 00:56:50
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size();

        int l = 0;
        int r = len-1;
        
        while (l < r) {
            int mid = (l+r) / 2;
            if (nums[mid] < target) {
                l = mid+1;
            } else {
                r = mid;
            }
        }
        
        return nums[l] == target ? l : -1;
    }
};
