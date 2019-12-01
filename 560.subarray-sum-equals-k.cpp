// CreateTime: 2019-11-30 23:47:17
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0;

        int len = nums.size();
        vector<int> sum(len+1);

        for (int i = 1; i <= len; i++) {
            sum[i] = sum[i-1] + nums[i-1];
        }

        unordered_map<int, int> m;
        m[0] = 1;
        for (int i = 1; i <= len; i++) {
            int target = sum[i] - k;
            ans += m[target];
            m[sum[i]] += 1;
        }
        
        return ans;
    }
};
