// CreateTime: 2020-12-04 00:39:26
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        typedef priority_queue<int, vector<int>, greater<int>> pq;
        unordered_map<int, pq> m;

        // m[x] 表示以 x 结尾的队列列表
        //
        // m[x] 是一个堆，假设堆的 sie 是 N。表示以 x 结尾的队列有个 N 个
        // m[x] 的堆顶部是当前所有队列中，长度最小的

        for (int i = 0; i < nums.size(); i++) {
            auto x = nums[i];

            if (m[x-1].size()) {
                int sz = m[x-1].top();
                m[x-1].pop();
                m[x].push(sz + 1);
            } else {
                m[x].push(1);
            }
        }

        for (auto &x: m) {
            if (x.second.size() == 0) {
                continue;
            }
            auto sz = x.second.top();
            if (1 <= sz && sz < 3) {
                return false;
            }
        }
        return true;
    }
};
