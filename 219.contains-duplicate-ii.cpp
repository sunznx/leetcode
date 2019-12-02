// CreateTime: 2019-12-02 10:43:51
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> m;

        int len = nums.size();
        for (int i = 0; i < len; i++) {
            if (m[nums[i]] == 0) {
                m[nums[i]] = i + 1;
            } else {
                if (i+1 - m[nums[i]] <= k) {
                    return true;
                }
                if (i+1 - m[nums[i]] > k) {
                    m[nums[i]] = i+1;
                }
            }
        }
        
        return false;
    }
};
