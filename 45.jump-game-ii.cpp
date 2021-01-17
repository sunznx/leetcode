// CreateTime: 2019-11-23 01:14:42
class Solution {
public:
    int jump(vector<int>& nums) {
        int W = nums.size()-1;

        vector<int> f(W+1, W+1);

        f[0] = 0;
        int w = 0;
        for (int i = 0; i < nums.size()-1; i++) {
            auto x = nums[i];
            for (int j = w; j <= i+x && j <= W; j++) {
                f[j] = min(f[j], f[i] + 1);
            }
            w = x + i;
        }
        return f[W];
    }
};

