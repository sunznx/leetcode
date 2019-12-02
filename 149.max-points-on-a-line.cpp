// CreateTime: 2019-12-01 14:34:39
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        unordered_map<int, int> t;

        int ans = 0;
        int len = points.size();

        for (int i = 0; i < len; i++) {
            auto x1 = points[i][0];
            auto y1 = points[i][1];

            t[x1] += 1;

            int dup = 0;
            for (int j = i+1; j < len; j++) {
                auto x2 = points[j][0];
                auto y2 = points[j][1];

                if (x1 == x2 && y1 == y2) {
                    dup += 1;
                }
            }

            unordered_map<long double, unordered_map<long double, int>> m;
            for (int j = i+1; j < len; j++) {
                auto x2 = points[j][0];
                auto y2 = points[j][1];

                if (x1 == x2) {
                    continue;
                }

                long double k = (long double)(y2-y1)/(x2-x1);
                long double b = y1 - (k*x1);

                m[k][b] += 1;
                ans = max(ans, m[k][b] + dup + 1);
            }

            ans = max(ans, t[x1]);
        }
        return ans;
    }
};