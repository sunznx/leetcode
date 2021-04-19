// CreateTime: 2021-04-18 10:25:07
class Solution {
public:
    typedef long long LL;
    typedef tuple<LL, LL, LL> TIII;
    typedef pair<LL, LL> PII;

    vector<int> ans;

    vector<int> getOrder(vector<vector<int>>& tasks) {
        int len = tasks.size();
        vector<TIII> S(len);
        for (int i = 0; i < len; i++) {
            auto x = tasks[i][0];
            auto y = tasks[i][1];
            S[i] = {x, y, i};
        }

        sort(S.begin(), S.end());

        priority_queue<PII, vector<PII>, greater<PII>> pq;

        int k = 0;
        LL end = 0;
        while (k < S.size() || pq.size()) {
            if (pq.size() == 0) {
                auto [x, y, idx] = S[k++];
                pq.push({y, idx});
            }

            auto top = pq.top();
            pq.pop();

            auto idx = top.second;
            ans.push_back(idx);
            end = max(end, (LL)tasks[idx][0]) + tasks[idx][1];

            while (k < S.size() && get<0>(S[k]) <= end) {
                auto [x, y, idx] = S[k++];
                pq.push({y, idx});
            }
        }
        return ans;
    }
};