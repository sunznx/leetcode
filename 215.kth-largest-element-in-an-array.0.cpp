// CreateTime: 2021-01-12 16:51:51
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int i = 0; i < nums.size(); i++) {
            auto x = nums[i];

            if (pq.size() < k) {
                pq.push(x);
            } else if (pq.size() == k && x > pq.top()) {
                pq.pop();
                pq.push(x);
            }
        }

        return pq.top();
    }
};
