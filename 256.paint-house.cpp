// CreateTime: 2019-12-11 17:49:17
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int len = costs.size();
        if (len == 0) {
            return 0;
        }
        
        vector<vector<int>> minCosts(len, vector<int>(3, 0x7fffffff));
        dfs(0, costs, minCosts, 0);
        auto x = minCosts[len-1];
        return min(min(x[0], x[1]), x[2]);
    }

    void dfs(int step, vector<vector<int>>& costs, vector<vector<int>> &minCosts, int cost, int pre = -1) {
        int len = costs.size();
        if (step == len) {
            return;
        }

        for (int i = 0; i < 3; i++) {
            if (i == pre) {
                continue;
            }
            
            if (cost + costs[step][i] >= minCosts[step][i]) {
                continue;
            }
            minCosts[step][i] = cost + costs[step][i];
            dfs(step + 1, costs, minCosts, cost+costs[step][i], i);
        }
    }
};
