// CreateTime: 2019-12-01 03:15:51
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int len = nums.size();

        for (int i = 0; i < len; i++) {
            if (nums[i] == 0) {
                nums[i] = -1;
            }
        }

        vector<int> sum(len+1);
        for (int i = 1; i <= len; i++) {
            sum[i] = sum[i-1] + nums[i-1];
        }

        int ans = 0;

        unordered_map<int, int> m;
        m[0] = 0;
        for (int i = 1; i <= len; i++) {
            int target = sum[i];

            if (m.find(target) == m.end()) {
                m[target] = i;
            } else {
                ans = max(ans, i-m[target]);
            }
        }

        return ans;
    }
};
