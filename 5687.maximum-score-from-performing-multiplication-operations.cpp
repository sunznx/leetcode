// CreateTime: 2021-02-21 10:40:42
class Solution {
public:
    int ans = INT_MIN;

    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n = nums.size();
        int m = multipliers.size();

        vector<vector<int>> f(m+1, vector<int>(m+1));

        // f[i][j] 表示前面取 i 个，后面取 j 个
        f[0][0] = 0;

        for (int i = 1; i <= m; i++) {
            f[0][i] = f[0][i-1] + nums[n-i]*multipliers[i-1];
        }

        for (int i = 1; i <= m; i++) {
            f[i][0] = f[i-1][0] + nums[i-1] * multipliers[i-1];
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= m; j++) {
                if (i+j <= m) {
                    auto x = nums[i-1];
                    auto y = nums[n-j];
                    f[i][j] = max(f[i][j-1]+y*multipliers[i+j-1], f[i-1][j]+x*multipliers[i+j-1]);

                    if (i+j == m) {
                        ans = max(ans, f[i][j]);
                    }
                }
            }
        }

        return ans;
    }
};