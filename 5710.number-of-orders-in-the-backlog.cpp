// CreateTime: 2021-03-22 08:37:14
class Solution {
public:
    typedef pair<int, int> PII;
    typedef long long LL;
    const int MOD = 1e9+7;

    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        priority_queue<PII, vector<PII>, less<PII>> buy;
        priority_queue<PII, vector<PII>, greater<PII>> sell;

        for (int i = 0; i < orders.size(); i++) {
            auto &price = orders[i][0];
            auto &amount = orders[i][1];
            auto &type = orders[i][2];

            if (type == 0) {
                while (sell.size() && sell.top().first <= price && amount > 0) {
                    auto idx = sell.top().second;
                    if (amount >= orders[idx][1]) {
                        amount -= orders[idx][1];
                        sell.pop();
                    } else {
                        orders[idx][1] -= amount;
                        amount = 0;
                    }
                }

                if (amount > 0) {
                    buy.push({price, i});
                }
            } else {
                while (buy.size() && buy.top().first >= price && amount > 0) {
                    auto idx = buy.top().second;
                    cout << amount << " " << orders[idx][1] << endl;
                    if (amount >= orders[idx][1]) {
                        amount -= orders[idx][1];
                        buy.pop();
                    } else {
                        orders[idx][1] -= amount;
                        amount = 0;
                    }
                }

                if (amount > 0) {
                    sell.push({price, i});
                }
            }
        }

        LL ans = 0;
        while (buy.size()) {
            auto top = buy.top();
            buy.pop();
            ans = (ans + orders[top.second][1]) % MOD;
        }
        while (sell.size()) {
            auto top = sell.top();
            sell.pop();
            ans = (ans + orders[top.second][1]) % MOD;
        }
        return ans;
    }
};
