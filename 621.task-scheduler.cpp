// CreateTime: 2020-12-07 07:25:50
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int ans = 0;

        vector<int> m(256);
        for (int i = 0; i < tasks.size(); i++) {
            auto x = tasks[i];
            m[x]++;
        }

        typedef pair<int, int> PII;
        priority_queue<PII, vector<PII>, less<PII>> pq;
        for (int i = 0; i < m.size(); i++) {
            if (m[i] > 0) {
                pq.push({m[i], i});
            }
        }

        while (pq.size()) {
            vector<PII> item;

            auto top = pq.top();
            if (top.first-1 > 0) {
                item.push_back({top.first-1, top.second});
            }
            pq.pop();
            ans++;

            for (int k = 0; k < n; k++) {
                if (pq.size()) {
                    auto top = pq.top();
                    if (top.first-1 > 0) {
                        item.push_back({top.first-1, top.second});
                    }
                    pq.pop();
                } else if (pq.size() == 0 && item.size() == 0) {
                    break;
                }
                ans++;
            }

            for (int i = 0; i < item.size(); i++) {
                auto x = item[i];
                if (x.first > 0) {
                    pq.push(x);
                }
            }
        }

        return ans;
    }
};
