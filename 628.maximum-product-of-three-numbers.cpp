// CreateTime: 2019-12-25 15:35:40
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        const int inf = 0x7fffffff;
        int max1 = -inf;
        int max2 = -inf;
        int max3 = -inf;
        int min1 = inf;
        int min2 = inf;

        int len = nums.size();
        for (int i = 0; i < len; i++) {
            if (nums[i] >= max1) {
                max3 = max2;
                max2 = max1;
                max1 = nums[i];
            } else if (nums[i] >= max2) {
                max3 = max2;
                max2 = nums[i];
            } else if (nums[i] >= max3) {
                max3 = nums[i];
            }

            if (nums[i] <= min1) {
                min2 = min1;
                min1 = nums[i];
            } else if (nums[i] <= min2) {
                min2 = nums[i];
            }
        }

        int ans = max1 * max2 * max3;
        if (min1 < 0 && min2 < 0) {
            ans = max(ans, max1 * min1 * min2);
        }
        return ans;
    }
};
