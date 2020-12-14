// CreateTime: 2020-12-14 11:40:54
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) {
            return 0;
        }

        vector<int> up(len, 1);
        vector<int> down(len, 1);

        for (int i = 1; i < len; i++) {
            auto x = nums[i];
            auto pre = nums[i-1];
            if (x > pre) {
                up[i] = max(up[i-1], down[i-1]+1);
                down[i] = down[i-1];
            } else if (x < pre) {
                up[i] = up[i-1];
                down[i] = max(up[i-1]+1, down[i-1]);
            } else {
                up[i] = up[i-1];
                down[i] = down[i-1];
            }
        }

        return max(up[len-1], down[len-1]);
    }
};
