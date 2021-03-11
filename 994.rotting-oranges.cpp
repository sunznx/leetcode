// CreateTime: 2021-03-11 18:18:54
class Solution {
public:
    typedef pair<int, int> PII;

    int step = -1;
    queue<PII> que;


    vector<int> dx = {0, -1, 0, 1};
    vector<int> dy = {-1, 0, 1, 0};

    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        int leaves = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 2) {
                    que.push({i, j});
                } else if (grid[i][j] == 1) {
                    leaves++;
                }
            }
        }

        while (que.size()) {
            auto sz = que.size();
            step++;

            while (sz--) {
                auto front = que.front();
                que.pop();

                auto x = front.first;
                auto y = front.second;

                for (int k = 0; k < 4; k++) {
                    auto newX = x + dx[k];
                    auto newY = y + dy[k];

                    if (0 <= newX && newX < row && 0 <= newY && newY < col && grid[newX][newY] == 1) {
                        grid[newX][newY] = 2;
                        que.push({newX, newY});
                        leaves--;
                    }
                }
            }
        }

        if (leaves > 0) {
            return -1;
        }
        return max(0, step);
    }
};
