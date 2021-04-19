// CreateTime: 2021-04-17 22:37:27
class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector<int> ans(nums.size());

        int m = 0;
        for (int i = 0; i < nums.size(); i++) {
            auto x = nums[i];
            m ^= x;

            int k = 0;
            for (int b = 0; b < maximumBit; b++) {
                if ((m & (1<<b)) == 0) {
                    k += (1<<b);
                }
            }

            ans[nums.size()-1-i] = k;
        }

        return ans;
    }
};