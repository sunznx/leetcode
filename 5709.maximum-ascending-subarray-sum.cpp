// CreateTime: 2021-03-22 08:27:45
class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int ans = 0;
        int sub = 0;

        int len = nums.size();
        sub = nums[0];
        ans = nums[0];
        for (int i = 1; i < len; i++) {
            if (nums[i] > nums[i-1]) {
                sub += nums[i];
            } else {
                sub = nums[i];
            }
            ans = max(ans, sub);
        }
        return ans;
    }
};
