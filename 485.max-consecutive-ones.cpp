class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int len = nums.size();
        int res = 0;
        int cur = 0;
        for (int i = 0; i < len; i++) {
            if (nums[i] == 1) {
                cur += 1;
            } else {
                cur = 0;
            }
            res = max(cur, res);
        }
        
        return res;
    }
};
