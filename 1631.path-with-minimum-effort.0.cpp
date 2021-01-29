// CreateTime: 2021-01-29 20:07:27
class Solution {
public:
    typedef pair<int, int> PII;
    queue<PII> que;

    vector<int> dx = { 0, -1, 0, 1};
    vector<int> dy = {-1,  0, 1, 0};

    int minimumEffortPath(vector<vector<int>>& heights) {
        auto row = heights.size();
        auto col = heights[0].size();

        vector<vector<bool>> seen(row, vector<bool>(col));
        vector<vector<int>> f(row, vector<int>(col, INT_MAX));

        que.push({0, 0});
        f[0][0] = 0;
        seen[0][0] = true;

        while (que.size()) {
            auto front = que.front();
            que.pop();

            auto x = front.first;
            auto y = front.second;
            seen[x][y] = false;

            for (int k = 0; k < 4; k++) {
                auto newX = x + dx[k];
                auto newY = y + dy[k];

                if (newX < 0 || newX >= row || newY < 0 || newY >= col) {
                    continue;
                }

                auto newV = abs(heights[newX][newY]-heights[x][y]);
                if (max(f[x][y], newV) < f[newX][newY]) {
                    f[newX][newY] = max(f[x][y], newV);
                    if (!seen[newX][newY]) {
                        que.push({newX, newY});
                        seen[newX][newY] = true;
                    }
                }
            }
        }

        return f[row-1][col-1];
    }
};
