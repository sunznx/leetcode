// CreateTime: 2021-03-07 10:39:55
class Solution {
public:
    typedef pair<int, int> PII;
    typedef long long LL;

    LL ans = 1;

    vector<int> d;
    vector<int> m;
    vector<vector<PII>> g;
    const int MOD = 1e9+7;

    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        d.resize(n+1, INT_MAX);
        m.resize(n+1);
        g.resize(n+1);

        for (auto &edge: edges) {
            auto x = edge[0];
            auto y = edge[1];
            auto w = edge[2];
            g[x].push_back({y, w});
            g[y].push_back({x, w});
        }


        queue<int> que;
        que.push(n);
        d[n] = 0;

        while (que.size()) {
            auto x = que.front();
            que.pop();

            for (auto &e: g[x]) {
                auto y = e.first;
                auto w = e.second;

                if (d[x]+w < d[y]) {
                    d[y] = d[x]+w;
                    que.push(y);
                }
            }
        }

        return dfs(n);
    }

    int dfs(int n, int x = 1, LL sub = 0) {
        if (m[x]) {
            return m[x];
        }

        for (auto &e: g[x]) {
            auto y = e.first;
            auto w = e.second;

            if (y == n) {
                sub++;
                continue;
            }

            if (d[y] >= d[x]) {
                continue;
            }

            sub += dfs(n, y);
        }

        sub = sub % MOD;
        return m[x] = sub;
    }
};