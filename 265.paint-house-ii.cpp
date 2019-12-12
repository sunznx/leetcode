// CreateTime: 2019-12-12 11:35:45
class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        if (costs.size() == 0 || costs[0].size() == 0) {
            return 0;
        }

        int len = costs.size();
        int k = costs[0].size();
        const int inf = 0x7fffffff;

        vector<vector<int>> minCosts(2, vector<int>(k, inf));

        for (int x = 0; x < k; x++) {
            minCosts[0][x] = 0;
        }

        for (int i = 0; i < len; i++) {
            for (int j = 0; j < k; j++) {
                int minv = inf;
                for (int x = 0; x < k; x++) {
                    if (i != 0 && x == j) {
                        continue;
                    }
                    minv = min(minv, minCosts[i%2][x]);
                }
                minCosts[(i+1)%2][j] = costs[i][j] + minv;
            }

        }

        int minv = inf;
        for (int x = 0; x < k; x++) {
            minv = min(minv, minCosts[(len)%2][x]);
        }
        return minv;
    }
};
