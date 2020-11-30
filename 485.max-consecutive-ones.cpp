// CreateTime: 2020-12-01 07:30:57
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;

        int cur = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                cur += 1;
            } else {
                cur = 0;
            }

            ans = max(ans, cur);
        }

        return ans;
    }
};
