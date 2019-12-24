// CreateTime: 2019-12-24 14:59:01
class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        auto x1 = points[0][0];
        auto y1 = points[0][1];

        auto x2 = points[1][0];
        auto y2 = points[1][1];

        auto x3 = points[2][0];
        auto y3 = points[2][1];

        if (x1 == x2 && x2 == x3) {
            return false;
        }

        if (x1 == x2 && y1 == y2 || x1 == x3 && y1 == y3 || x2 == x3 && y2 == y3) {
            return false;
        }

        if (x1 == x2 || x1 == x3 || x2 == x3) {
            return true;
        }

        double k1 = (double)((y2-y1)/(x2-x1));
        double b1 = (double)(y2-k1*x2);

        double k2 = (double)((y2-y3)/(x2-x3));
        double b2 = (double)(y2-k2*x2);

        double k3 = (double)((y3-y1)/(x3-x1));
        double b3 = (double)(y3-k3*x3);

        if (k1 == k2 && b1 == b2 && k1 == k3 && b1 == b3) {
            return false;
        }
        return true;
    }
};
