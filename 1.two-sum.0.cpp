// CreateTime: 2020-11-30 07:54:21
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        vector<int> ans(2, -1);
        for (int i = 0; i < nums.size(); i++) {
            auto x = nums[i];
            m[x] = i;
        }

        for (int i = 0; i < nums.size(); i++) {
            auto x = nums[i];
            auto k = target - x;
            if (m.find(k) != m.end() && m[k] != i) {
                ans[0] = i;
                ans[1] = m[k];
                break;
            }
        }
        return ans;
    }
};
