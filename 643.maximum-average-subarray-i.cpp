class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int len = nums.size();
        int current = 0;
        for (int i = 0; i < k; i++) {
            current += nums[i];
        }
        
        int maxN = current;
        for (int i = 1; i <= len-k; i++) {
            current = current - nums[i-1] + nums[i-1+k];
            maxN = max(maxN, current);
        }
        
        return double(maxN / double(k));
    }
};
