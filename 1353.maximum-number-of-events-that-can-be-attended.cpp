// CreateTime: 2021-02-08 16:02:38
class Solution {
public:
    int ans = 0;
    const int MAX = 1e5;
    priority_queue<int, vector<int>, greater<int>> pq;

    int maxEvents(vector<vector<int>>& events) {
        unordered_map<int, vector<int>> m;

        for (auto &x: events) {
            auto start = x[0];
            auto end = x[1];

            m[start].push_back(end);
        }

        for (int i = 1; i <= MAX; i++) {
            for (auto &end: m[i]) {
                pq.push(end);
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
