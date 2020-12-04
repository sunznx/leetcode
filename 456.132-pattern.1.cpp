// CreateTime: 2020-12-04 08:51:28
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int len = nums.size();
        vector<int> minL(len);
        vector<int> maxR(len);

        for (int i = 0; i < len; i++) {
            if (i == 0) {
                minL[i] = nums[i];
            } else {
                minL[i] = min(minL[i-1], nums[i]);
            }
        }

        deque<int> que;
        for (int i = len-1; i >= 0; i--) {
            maxR[i] = nums[i];
            while (que.size() && que.front() < nums[i]) {
                maxR[i] = que.front();
                que.pop_front();
            }
            que.push_front(nums[i]);
        }

        for (int i = 0; i < len; i++) {
            if (minL[i] < maxR[i] && maxR[i] < nums[i]) {
                return true;
            }
        }

        return false;
    }
};
