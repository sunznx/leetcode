// CreateTime: 2020-11-21 08:38:42
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int len = nums.size();
        
        deque<pair<int, int>> q;

        vector<int> ans;

        for (int i = 0; i < len; i++) {
            auto num = nums[i];
            
            while (q.size() && i-q.front().first >= k) {
                q.pop_front();
            }

            while (q.size() && (num >= q.back().second)) {
                q.pop_back();
            }
            
            q.push_back({i, num});
            
            if (i+1 >= k) {
                ans.push_back(q.front().second);
            }
        }
        
        return ans;
    }
};
