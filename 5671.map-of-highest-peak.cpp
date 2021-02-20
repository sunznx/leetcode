// CreateTime: 2021-02-20 23:20:59
class Solution {
public:
    typedef pair<int, int> PII;

    vector<int> dx = { 0, -1, 0, 1};
    vector<int> dy = {-1,  0, 1, 0};

    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int row = isWater.size();
        int col = isWater[0].size();

        vector<vector<int>> g(row, vector<int>(col, -1));

        queue<PII> q;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (isWater[i][j] == 1) {
                    q.push({i, j});
                    g[i][j] = 0;
                }
            }
        }

        while (q.size()) {
            auto sz = q.size();

            for (int k = 0; k < sz; k++) {
                auto top = q.front();
                q.pop();

                auto x = top.first;
                auto y = top.second;
                for (int z = 0; z < 4; z++) {
                    auto newX = x + dx[z];
                    auto newY = y + dy[z];

                    if (0 <= newX && newX < row && 0 <= newY && newY < col && g[newX][newY] == -1) {
                        q.push({newX, newY});
                        g[newX][newY] = g[x][y]+1;
                    }
                }
            }
        }

        return g;
    }
};