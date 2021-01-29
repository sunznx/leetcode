// CreateTime: 2021-01-29 03:03:09
class Solution {
public:
    typedef tuple<int, int, int> TIII;
    priority_queue<TIII, vector<TIII>, greater<TIII>> pq;

    vector<int> dx = { 0, -1, 0, 1};
    vector<int> dy = {-1,  0, 1, 0};

    int minimumEffortPath(vector<vector<int>>& heights) {
        auto row = heights.size();
        auto col = heights[0].size();

        vector<vector<bool>> seen(row, vector<bool>(col));
        vector<vector<int>> f(row, vector<int>(col, INT_MAX));

        pq.push({0, 0, 0});
        f[0][0] = 0;

        while (pq.size()) {
            auto top = pq.top();
            pq.pop();

            auto [v, x, y] = top;

            if (seen[x][y]) {
                continue;
            }

            seen[x][y] = true;

            for (int k = 0; k < 4; k++) {
                auto newX = x + dx[k];
                auto newY = y + dy[k];

                if (newX < 0 || newX >= row || newY < 0 || newY >= col || seen[newX][newY]) {
                    continue;
                }

                auto newV = abs(heights[newX][newY]-heights[x][y]);
                f[newX][newY] = min(f[newX][newY], max(v, newV));
                pq.push({f[newX][newY], newX, newY});
            }
        }

        return f[row-1][col-1];
    }
};