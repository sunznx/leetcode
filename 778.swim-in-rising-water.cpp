// CreateTime: 2021-01-30 15:48:52
class Solution {
public:
    typedef tuple<int, int, int> TIII;

    vector<int> dx = { 0, -1, 0, 1};
    vector<int> dy = {-1,  0, 1, 0};

    priority_queue<TIII, vector<TIII>, greater<TIII>> pq;

    int swimInWater(vector<vector<int>>& grid) {
        auto row = grid.size();
        auto col = grid[0].size();

        vector<vector<int>> f(row, vector<int>(col, INT_MAX));
        vector<vector<bool>> seen(row, vector<bool>(col));

        pq.push({grid[0][0], 0, 0});
        f[0][0] = grid[0][0];

        while (pq.size()) {
            auto [v, x, y] = pq.top();
            pq.pop();

            if (seen[x][y]) {
                continue;
            }

            seen[x][y] = true;

            for (int k = 0; k < 4; k++) {
                auto newX = x + dx[k];
                auto newY = y + dy[k];

                if (newX < 0 || newY < 0 || newX >= row || newY >= col || seen[newX][newY]) {
                    continue;
                }

                auto &newV = f[newX][newY];
                newV = min(newV, max(grid[newX][newY], f[x][y]));
                pq.push({newV, newX, newY});
            }
        }

        return f[row-1][col-1];
    }
};
