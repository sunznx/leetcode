// CreateTime: 2021-04-18 10:25:01
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int ans = 0;
        sort(costs.begin(), costs.end());
        for (auto &x: costs) {
            if (coins >= x) {
                coins -= x;
                ans++;
            } else {
                break;
            }
        }
        return ans;
    }
};