// CreateTime: 2020-01-09 07:55:24
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int times1 = 0;
        int times2 = 0;
        int res1;
        int res2;

        int len = nums.size();
        for (int i = 0; i < len; i++) {
            if (times1 != 0 && res1 == nums[i]) {
                times1++;
                continue;
            }
            if (times2 != 0 && res2 == nums[i]) {
                times2++;
                continue;
            }

            if (times1 == 0) {
                res1 = nums[i];
                times1++;
                continue;
            }

            if (times2 == 0) {
                res2 = nums[i];
                times2++;
                continue;
            }
            times1--;
            times2--;
        }

        int k1 = 0;
        int k2 = 0;
        for (int i = 0; i < len; i++) {
            if (times1 > 0 && nums[i] == res1) {
                k1++;
            }
            if (times2 > 0 && nums[i] == res2) {
                k2++;
            }
        }

        vector<int> res;
        if (k1 > len/3) {
            res.push_back(res1);
        }
        if (k2 > len/3) {
            res.push_back(res2);
        }
        return res;
    }
};
