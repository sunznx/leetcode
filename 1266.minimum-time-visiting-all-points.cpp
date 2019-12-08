// CreateTime: 2019-12-09 07:11:42
class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int res = 0;
        
        int len = points.size();
        for (int i = 1; i < len; i++) {
            auto x = points[i][0];
            auto y = points[i][1];
            
            auto preX = points[i-1][0];
            auto preY = points[i-1][1];
            
            int d1 = min(abs(preX-x), abs(preY-y));
            int d2 = max(abs(preX-x), abs(preY-y));
            
            res += d1 + (d2-d1);
        }

        return res;
    }
};
