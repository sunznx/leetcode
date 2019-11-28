// CreateTime: 2019-11-28 10:07:36
class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int len = ops.size();
        
        int minx = m;
        int miny = n;
        for (int i = 0; i < len; i++) {
            int x = ops[i][0];
            int y = ops[i][1];
            
            minx = min(minx, x);
            miny = min(miny, y);
        }
        
        return minx * miny;
    }
};