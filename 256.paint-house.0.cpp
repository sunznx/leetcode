// CreateTime: 2019-12-12 11:02:55
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int len = costs.size();
        if (len == 0) {
            return 0;
        }

        vector<vector<int>> minCosts(2, vector<int>(3, 0x7fffffff));
        
        minCosts[0][0] = 0;
        minCosts[0][1] = 0;
        minCosts[0][2] = 0;

        for (int i = 0; i < len; i++) {
            minCosts[(i+1)%2][0] = costs[i][0] + min(minCosts[i%2][1], minCosts[i%2][2]);
            minCosts[(i+1)%2][1] = costs[i][1] + min(minCosts[i%2][0], minCosts[i%2][2]);
            minCosts[(i+1)%2][2] = costs[i][2] + min(minCosts[i%2][0], minCosts[i%2][1]);
        }
        
        auto x = minCosts[(len)%2];
        return min(min(x[0], x[1]), x[2]);
    }
};
