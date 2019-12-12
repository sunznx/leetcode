// CreateTime: 2019-12-11 17:49:17
class Solution {
public:
    int ans = 0x7fffffff;

    int minCost(vector<vector<int>>& costs) {
        vector<vector<int>> minCosts(costs.size(), vector<int>(3, ans));
        dfs(0, costs, minCosts, 0);
        return ans;
    }

    void dfs(int step, vector<vector<int>>& costs, vector<vector<int>> &minCosts, int cost, int pre = -1) {
        int len = costs.size();
        if (step == len) {
            ans = min(ans, cost);
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
