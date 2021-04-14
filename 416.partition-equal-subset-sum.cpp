// CreateTime: 2021-04-15 01:19:22
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int len = nums.size();
        int S = accumulate(nums.begin(), nums.end(), 0);
        if (S % 2 != 0) {
            return false;
        }

        int target = S / 2;
        int maxVal = *max_element(nums.begin(), nums.end());
        if (maxVal > target) {
            return false;
        }

        vector<vector<bool>> f(len, vector<bool>(target+1));
        for (int i = 0; i < len; i++) {
            f[i][0] = true;
        }

        f[0][nums[0]] = true;

        for (int i = 1; i < len; i++) {
            auto x = nums[i];
            f[i][x] = true;

            for (int j = 1; j <= target; j++) {
                if (j >= x) {
                    f[i][j] = (f[i-1][j] || f[i-1][j-x]);
                } else {
                    f[i][j] = f[i-1][j];
                }
            }
        }

        return f[len-1][target];
    }
};
