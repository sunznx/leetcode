// CreateTime: 2021-04-24 00:14:39
class Solution {
public:
    typedef unsigned long long ULL;

    int combinationSum4(vector<int>& nums, int target) {
        vector<ULL> f(target+1, 0);
        f[0] = 1;
        for (int j = 0; j <= target; j++) {
            for (auto &x: nums) {
                if (j >= x) {
                    f[j] += f[j-x];
                }
            }
        }
        return f[target];
    }
};

