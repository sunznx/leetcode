// CreateTime: 2021-02-18 14:50:43
class Solution {
public:
    unordered_map<int, unordered_set<int>> m;

    int minTrioDegree(int n, vector<vector<int>>& edges) {
        vector<vector<bool>> g(n+1, vector<bool>(n+1));
        vector<int> d(n+1);

        for (auto &edge: edges) {
            auto x = edge[0];
            auto y = edge[1];

            g[x][y] = true;
            g[y][x] = true;
            d[x]++;
            d[y]++;
        }

        int ans = INT_MAX;

        for (int i = 1; i <= n; i++) {
            for (int j = i+1; j <= n; j++) {
                if (g[i][j] == false) {
                    continue;
                }

                for (int k = j+1; k <= n; k++) {
                    if (g[i][k] == false || g[j][k] == false) {
                        continue;
                    }

                    int x = d[i]-2 + d[j]-2 + d[k]-2;
                    ans = min(ans, x);
                }
            }
        }

        if (ans == INT_MAX) {
            return -1;
        }

        return ans;
    }
};