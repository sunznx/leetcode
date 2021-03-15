// CreateTime: 2021-03-06 22:36:05
class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int val = INT_MAX;
        int ans = -1;

        for (int i = 0; i < points.size(); i++) {
            auto k1 = points[i][0];
            auto k2 = points[i][1];

            auto newVal = abs(k1-x) + abs(k2-y);

            if ((k1 == x || k2 == y) && (newVal < val)) {
                val = newVal;
                ans = i;
            }
        }

        return ans;
    }
};