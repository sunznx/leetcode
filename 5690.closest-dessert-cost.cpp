// CreateTime: 2021-02-28 10:35:49
class Solution {
public:
    int cost = INT_MAX;
    int diff = INT_MAX;

    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        for (auto &base: baseCosts) {
            dfs(baseCosts, toppingCosts, target, base);
        }

        return cost;
    }

    void dfs(vector<int>& baseCosts, vector<int>& toppingCosts, int target, int c, int step = 0) {
        if (step >= toppingCosts.size()) {
            return;
        }

        auto topping = toppingCosts[step];
        for (int k = 0; k <= 2; k++) {
            int newCost = c + topping * k;
            int newDiff = abs(newCost - target);
            if (newDiff < diff || newDiff == diff && newCost < cost) {
                cost = newCost;
                diff = newDiff;
            }
            dfs(baseCosts, toppingCosts, target, newCost, step+1);
        }
    }
};