// CreateTime: 2019-11-30 15:46:16
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;

        int len = nums.size();
        for (int i = 0; i < len; i++) {
            m[nums[i]] = i;
        }

        for (int i = 0; i < len; i++) {
            int k = target-nums[i];
            if (m.find(k) != m.end() && m[k] != i) {
                return {i, m[k]};
            }
        }
        return {-1, -1};
    }
};

