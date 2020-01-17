// CreateTime: 2020-01-18 01:17:14
class Solution {
  public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<pair<int, int>> q;

        int len = points.size();
        for (int i = 0; i < len; i++) {
            auto x = points[i][0];
            auto y = points[i][1];
            auto d = (x*x) + (y*y);

            if (q.size() < K) {
                q.push({d, i});
            } else if (d < q.top().first) {
                q.pop();
                q.push({d, i});
            }
        }

        vector<vector<int>> res;
        while (q.size()) {
            auto k = q.top().second;
            q.pop();
            res.push_back(points[k]);
        }
        return res;
    }
};
