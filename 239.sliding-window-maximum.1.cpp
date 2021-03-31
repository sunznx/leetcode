// CreateTime: 2021-03-31 15:28:07
class Solution {
public:
    vector<int> ans;

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> que;

        for (int i = 0; i < nums.size(); i++) {
            auto x = nums[i];

            while (que.size() && que.front()+k-1 < i) {
                que.pop_front();
            }

            while (que.size() && x >= nums[que.back()]) {
                que.pop_back();
            }

            que.push_back(i);

            if (i >= k-1) {
                ans.push_back(nums[que.front()]);
            }
        }

        return ans;
    }
};
