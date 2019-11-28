// CreateTime: 2019-11-28 10:18:13
class Solution {
public:

    struct Point {
        int x;
        int y;

        int distance(Point &p) {
            return (x-p.x)*(x-p.x) + (y-p.y)*(y-p.y);
        }
    };

    int numberOfBoomerangs(vector<vector<int>>& points) {
        int len = points.size();

        vector<Point> p(len);

        vector<unordered_map<int, int>> distance(len);

        for (int i = 0; i < len; i++) {
            p[i].x = points[i][0];
            p[i].y = points[i][1];
        }

        for (int i = 0; i < len; i++) {
            for (int j = 0; j < len; j++) {
                int d = p[i].distance(p[j]);
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