class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int len = nums.size();
        vector<int> v(len+1, 0);
        
        for (int i = 0; i < len; i++) {
            v[nums[i]] = 1;
        }
        
        for (int i = 0; i <= len; i++) {
            if (!v[i]) {
                return i;
            }
        }
        
        return 0;
    }
};
