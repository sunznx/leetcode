// CreateTime: 2019-12-21 08:59:16
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(), [](auto cost1, auto cost2) {
                 return abs(cost1[0]-cost1[1]) > abs(cost2[0]-cost2[1]);
             });

        int ans = 0;
        int len = costs.size();

        int A = 0;
        int B = 0;
        for (int i = 0; i < len; i++) {
            if (A == len/2) {
                ans += costs[i][1];
                B++;
            } else if (B == len/2) {
                ans += costs[i][0];
                A++;
            } else if (costs[i][0] < costs[i][1]) {
                ans += costs[i][0];
                A++;
            } else {
                ans += costs[i][1];
                B++;
            }
        }
        return ans;
    }
};
