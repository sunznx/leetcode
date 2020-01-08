// CreateTime: 2020-01-08 15:23:11
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int len = points.size();
        if (len == 0) {
            return 0;
        }

        sort(points.begin(), points.end(), [](const auto &a, const auto &b) {
            return a[0] < b[0];
        });

        int res = len;
        int start = points[0][0];
        int end = points[0][1];
        for (int i = 1; i < len; i++) {
            if (points[i][0] > end) {
                start = points[i][0];
                end = points[i][1];
            } else {
                start = points[i][0];
                end = min(end, points[i][1]);
                res--;
            }
        }

        return res;
    }
};