// CreateTime: 2019-11-28 10:18:13
class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int len = points.size();

        vector<pair<int, int>> p(len);

        vector<unordered_map<int, int>> distance(len);

        for (int i = 0; i < len; i++) {
            p[i].first = points[i][0];
            p[i].second = points[i][1];
        }

        for (int i = 0; i < len; i++) {
            for (int j = 0; j < len; j++) {
                int x = (p[i].first - p[j].first);
                int y = (p[i].second - p[j].second);
                int d = x*x+y*y;
                distance[i][d] += 1;
            }
        }

        int ans = 0;
        for (int i = 0; i < len; i++) {
            for (auto &item: distance[i]) {
                auto d = item.first;
                auto size = item.second;
                ans +=  size * (size-1);
            }
        }

        return ans;
    }
};