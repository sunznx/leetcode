// CreateTime: 2021-04-25 10:32:52
class Solution {
public:
    typedef long long LL;

    int maxFrequency(vector<int>& nums, int k) {
        int len = nums.size();
        sort(nums.begin(), nums.end());

        vector<LL> d(len);
        for (int i = 1; i < len; i++) {
            d[i] = nums[i]-nums[i-1];
        }

        int ans = 0;
        int l = 0;
        LL sum = 0;
        for (int r = 0; r < len; r++) {
            sum += d[r]*(r-l);
            while (sum > k) {
                sum -= nums[r]-nums[l++];
            }

            ans = max(ans, r-l+1);
        }
        return ans;
    }
};