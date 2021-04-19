// CreateTime: 2021-04-11 10:20:29
class Solution {
public:
    int arraySign(vector<int>& nums) {
        int b = 0;
        for (auto &x: nums) {
            if (x == 0) {
                return 0;
            }

            if (x < 0) {
                b++;
            }
        }

        if (b % 2 == 0) {
            return 1;
        }
        return -1;
    }
};