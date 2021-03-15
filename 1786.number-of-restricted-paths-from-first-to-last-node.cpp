// CreateTime: 2021-03-07 10:39:55
class Solution {
public:
    typedef long long LL;
    typedef pair<LL, LL> PLL;

    vector<LL> d;
    vector<LL> m;
    vector<bool> seen;
    vector<vector<PLL>> g;
    priority_queue<PLL, vector<PLL>, greater<PLL>> pq;
    const int MOD = 1e9+7;

    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        d.resize(n+1, INT_MAX);
        m.resize(n+1, -1);
        g.resize(n+1);
        seen.resize(n+1);

        for (auto &edge: edges) {
            auto x = edge[0];
            auto y = edge[1];
            auto w = edge[2];
            g[x].push_back({y, w});
            g[y].push_back({x, w});
        }


        pq.push({0, n});
        d[n] = 0;

        while (pq.size()) {
            auto top = pq.top();
            pq.pop();

            auto dist = top.first;
            auto x = top.second;
            if (seen[x]) {
                continue;
            }

            seen[x] = true;

            for (auto &e: g[x]) {
                auto y = e.first;
                auto w = e.second;

                if (!seen[y]) {
                    d[y] = min(d[y], d[x]+w);
                    pq.push({d[y], y});
                }
            }
        }

        return dfs(n);
    }

    int dfs(int n, int x = 1, LL sub = 0) {
        if (m[x] != -1) {
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

