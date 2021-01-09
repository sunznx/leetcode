// CreateTime: 2021-01-09 16:30:14
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0];
        int sub = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            auto x = nums[i];
            sub += x;

            ans = max({ans, sub, x});
            sub = max({sub, x});
        }

        return ans;
    }
};
