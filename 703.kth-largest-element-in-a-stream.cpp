// CreateTime: 2019-12-06 11:40:38
class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> q;
    int K;

    KthLargest(int k, vector<int>& nums) {
        K = k;

        int len = nums.size();
        for (int i = 0; i < len; i++) {
            add(nums[i]);
        }
    }

    int add(int val) {
        if (q.size() == K) {
            if (val > q.top()) {
                q.pop();
                q.push(val);
            }
        } else {
            q.push(val);
        }

        return q.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
