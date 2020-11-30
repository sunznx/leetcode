// CreateTime: 2020-12-01 07:28:18
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;

        int l = 0;
        int r = 0;

        int usedK = 0;

        while (r < nums.size()) {
            auto x = nums[r++];

            if (x == 0) {
                usedK++;
            }

            while (usedK > 1) {
                auto y = nums[l++];
                if (y == 0) {
                    usedK--;
                }
            }

            ans = max(ans, r-l);
        }

        return ans;
    }
};
