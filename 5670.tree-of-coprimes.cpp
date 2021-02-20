// CreateTime: 2021-02-20 23:34:00
class Solution {
public:
    vector<int> ans;
    vector<int> d;
    vector<int> mark;    // mark[x] 表示数字 x 之前到过的路径
    vector<vector<bool>> f;
    vector<vector<int>> g;

    vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {
        int len = nums.size();

        d.resize(len, -1);
        ans.resize(len, -1);
        mark.resize(51, -1);
        f.resize(51, vector<bool>(51));
        g.resize(len);

        for (int i = 1; i <= 50; i++) {
            for (int j = 1; j <= 50; j++) {
                if (gcd(i, j) == 1) {
                    f[i][j] = true;
                }
            }
        }

        for (auto &edge: edges) {
            auto x = edge[0];
            auto y = edge[1];
            g[x].push_back(y);
            g[y].push_back(x);
        }

        dfs(nums);

        return ans;
    }

    void dfs(vector<int> &nums, int x = 0, int depth = 0) {
        if (d[x] != -1) {
            return;
        }

        d[x] = depth;

        int maxDepth = -1;
        for (int y = 1; y <= 50; y++) {
            if (f[nums[x]][y] == 1 && mark[y] != -1 && d[mark[y]] > maxDepth) {
                maxDepth = d[mark[y]];
                ans[x] = mark[y];
            }
        }

        int backup = mark[nums[x]];
        mark[nums[x]] = x;
        for (auto &j: g[x]) {
            dfs(nums, j, depth+1);
        }
        mark[nums[x]] = backup;
    }

    int gcd(int a, int b) {
        if (a < b) {
            return gcd(b, a);
        }

        if (b == 0) {
            return a;
        }

        return gcd(b, a % b);
    }
};