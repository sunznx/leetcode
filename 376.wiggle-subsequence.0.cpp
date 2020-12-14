// CreateTime: 2020-12-15 02:45:10
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) {
            return 0;
        }

        int up = 1;
        int down = 1;

        for (int i = 1; i < len; i++) {
            auto x = nums[i];
            auto pre = nums[i-1];

            if (x > pre) {
                up = down+1;
            } else if (x < pre) {
                down = up+1;
            }
        }

        return max(up, down);
    }
};
