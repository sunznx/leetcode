// CreateTime: 2019-11-26 23:58:52
class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int len = nums.size();

        int ans = 0;
        for (int k = 1; k < len; k++) {
            ans += (nums[k] - nums[k-1]) * (len-k);
        }
        return ans;
    }
};
