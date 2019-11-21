// CreateTime: 2019-11-21 21:22:37
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int len = nums.size();

        deque<pair<int, int>> q;
        vector<int> res;

        for (int i = 0; i < len; i++) {
            while (!q.empty() && nums[i] > q.back().first) {
                q.pop_back();
            }

            while (!q.empty() && q.front().second+k <= i) {
                q.pop_front();
            }

            q.push_back({nums[i], i});

            if (i >= k-1) {
                res.push_back(q.front().first);
            }
        }

        return res;
    }
};
