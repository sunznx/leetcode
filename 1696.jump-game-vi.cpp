// CreateTime: 2021-01-17 18:03:57
class Solution {
public:
    deque<int> que;
    int maxResult(vector<int>& nums, int k) {
        int len = nums.size();
        vector<int> f(len);

        f[0] = nums[0];
        que.push_back(0);

        for (int i = 1; i < len; i++) {
            while (que.size() && que.front()+k < i) {
                que.pop_front();
            }

            f[i] = nums[i] + f[que.front()];

            while (que.size() && f[i] >= f[que.back()]) {
                que.pop_back();
            }

            que.push_back(i);
        }
        return f[len-1];
    }
};
