// CreateTime: 2019-11-28 11:24:42
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        unordered_map<int, int> m;
        auto sorted = nums;
        sort(sorted.begin(), sorted.end(), greater<int>());
        
        int len = sorted.size();

        for (int i = 0; i < len; i++) {
            m[sorted[i]] = i+1;
        }

        vector<string> res;
        for (int i = 0; i < len; i++) {
            if (m[nums[i]] == 1) {
                res.push_back("Gold Medal");
            } else if (m[nums[i]] == 2) {
                res.push_back("Silver Medal");
            } else if (m[nums[i]] == 3) {
                res.push_back("Bronze Medal");
            } else {
                res.push_back(to_string(m[nums[i]]));
            }
        }
        return res;
    }
};
