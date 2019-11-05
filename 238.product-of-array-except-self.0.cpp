class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> ans(len, 1);
        int cur;

        cur = 1;
        for (int i = 1; i < len; i++) {
            ans[i] = cur * nums[i-1];
            cur = cur * nums[i-1];
        }

        cur = 1;
        for (int i = len-1; i >= 0; i--) {
            ans[i] = cur * ans[i];
            cur = cur * nums[i];

        }
        return ans;
    }
};