// CreateTime: 2019-12-02 10:43:51
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> m;

        int len = nums.size();
        for (int i = 0; i < len; i++) {
            if (m.find(nums[i]) == m.end()) {
                m[nums[i]] = i;
            } else {
                if (i - m[nums[i]] <= k) {
                    return true;
                }
                if (i - m[nums[i]] > k) {
                    m[nums[i]] = i;
                }
            }
        }
        
        return false;
    }
};
