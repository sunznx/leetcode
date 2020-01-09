// CreateTime: 2020-01-04 21:25:48
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> m;
        
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            m.insert(nums[i]);
        }
        
        for (int i = 1; i <= len; i++) {
            if (m.find(i) == m.end()) {
                return i;
            }
        }

        return len+1;
    }
};
