// CreateTime: 2019-12-09 00:35:21
class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        vector<vector<int>> res;
        map<
            int,
            priority_queue<int, vector<int>, greater<int>>
            > m;

        int len = items.size();
        for (int i = 0; i < len; i++) {
            auto id = items[i][0];
            auto credit = items[i][1];

            if (m[id].size() < 5) {
                m[id].push(credit);
            } else if (m[id].top() < credit) {
                m[id].pop();
                m[id].push(credit);
            }
        }

        for (auto &item: m) {
            auto id = item.first;
            auto q = item.second;
            long long s = 0;
            long long cnt = 0;
            for (cnt = 0; cnt < 5 && !q.empty(); cnt++) {
                s += q.top();
                q.pop();
            }

            res.push_back({id, s/cnt});
        }


        return res;
    }
};
