class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if (k < 0) {
            k = -k;
        }

        int len = nums.size();
        vector<int> sum(len, 0);

        int total = 0;
        for (int i = 0; i < len; i++) {
            sum[i] += nums[i] + total;
            total += nums[i];
        }

        for (int l = 2; l <= len; l++) {
            for (int i = 0; i+l <= len; i++) {
                int t = l+i-1;

                int res;
                if (i == 0) {
                    res = sum[t];
                } else {
                    res = sum[t] - sum[i-1];
                }

                if ((k == 0 && res == 0) || (k != 0 && res % k == 0)) {
                    return true;
                }
            }
        }

        return false;
    }
};
