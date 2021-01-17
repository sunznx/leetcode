// CreateTime: 2019-11-23 01:14:42
class Solution {
public:
    int jump(vector<int>& nums) {
        int len = nums.size();

        vector<int> f(len, len);

        f[0] = 0;
        int w = 0;
        for (int i = 0; i < nums.size()-1; i++) {
            auto x = nums[i];
            for (int j = w+1; j <= i+x && j <= len-1; j++) {
                f[j] = min(f[j], f[i] + 1);
            }
            w = x + i;
        }
        return f[len-1];
    }
};

