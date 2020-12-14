// CreateTime: 2020-12-15 02:47:56
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int len = nums.size();
        if (len <= 1) {
            return len;
        }

        int ans = 0;
        if (nums[0] == nums[1]) {
            ans = 1;
        } else {
            ans = 2;
        }

        int preDiff = nums[1] - nums[0];
        for (int i = 2; i < len; i++) {
            auto diff = nums[i] - nums[i-1];

            if ((preDiff >= 0 && diff < 0) || (preDiff <= 0 && diff > 0)) {
                preDiff = diff;
                ans++;
            }
        }

        return ans;
    }
};
