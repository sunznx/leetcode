// CreateTime: 2021-02-06 22:33:23
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxVal = INT_MIN;
        int minVal = INT_MAX;

        int maxSum = 0;
        int minSum = 0;
        for (auto &x: nums) {
            maxSum = max(maxSum+x, x);
            maxVal = max(maxVal, maxSum);

            minSum = min(minSum+x, x);
            minVal = min(minVal, minSum);
        }

        return max(abs(minVal), abs(maxVal));
    }
};