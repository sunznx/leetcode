// CreateTime: 2019-11-30 15:46:16
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;

        int len = nums.size();
        for (int i = 0; i < len; i++) {
            m[nums[i]] = i+1;
        }

        for (int i = 0; i < len; i++) {
            int k = target-nums[i];
            if (m[k] != 0 && m[k]-1 != i) {
                return {i, m[k]-1};
            }
        }
        return {-1, -1};
    }
};

