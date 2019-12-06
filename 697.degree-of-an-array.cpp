// CreateTime: 2019-12-06 16:10:49
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> c;
        unordered_map<int, pair<int,int>> m;
        int maxOccur = 0;

        int ans = 0;
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            if (m.find(nums[i]) == m.end()) {
                m[nums[i]].first = i;                
                m[nums[i]].second = i;                
            } else {                
                m[nums[i]].second = i;
            }

            int d = m[nums[i]].second - m[nums[i]].first + 1;

            c[nums[i]] += 1;
            if (c[nums[i]] > maxOccur) {
                maxOccur = c[nums[i]];
                ans = d;
            } else if (c[nums[i]] == maxOccur) {
                ans = min(ans, d);
            }
        }
        return ans;
    }
};
