// CreateTime: 2019-12-25 15:35:40
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int len = nums.size();

        int ans = nums[len-1] * nums[len-2] * nums[len-3];
        if (nums[0] < 0 && nums[1] < 0) {
            ans = max(ans, nums[0] * nums[1] * nums[len-1]);
        }
        return ans;
    }
};
