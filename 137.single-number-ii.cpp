class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int, int> m;
        int len = nums.size();
        int res = 0;
        for (int i = 0; i < len; i++) {
            if (m.find(nums[i]) == m.end()) {
                m[nums[i]] = 1;
            } else {
                m[nums[i]] += 1;                
            }
        }
        
        for (auto iter = m.begin(); iter != m.end(); iter++) {
            if (iter->second == 1) {
                return iter->first;
            }
        }
        
        return 0;
    }
};
