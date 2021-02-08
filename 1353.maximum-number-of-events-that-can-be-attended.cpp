// CreateTime: 2021-02-08 16:02:38
class Solution {
public:
    int ans = 0;
    priority_queue<int, vector<int>, greater<int>> pq;

    int maxEvents(vector<vector<int>>& events) {
        unordered_map<int, vector<int>> m;

        int l = INT_MAX;
        int r = INT_MIN;

        for (auto &x: events) {
            auto start = x[0];
            auto end = x[1];

            m[start].push_back(end);

            l = min(l, start);
            r = max(r, end);
        }

        for (int i = l; i <= r; i++) {
            for (auto &x: m[i]) {
                pq.push(x);
            }

            // 过滤掉过期的时间
            while (pq.size() && pq.top() < i) {
                pq.pop();
            }

            if (pq.size()) {
                pq.pop();
                ans++;
            }
        }

        return ans;
    }
};
