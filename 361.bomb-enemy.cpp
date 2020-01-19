// CreateTime: 2020-01-19 11:37:01
class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) {
            return 0;
        }

        int row = grid.size();
        int col = grid[0].size();

        int res = 0;
        for (int x = 0; x < row; x++) {
            for (int y = 0; y < col; y++) {
                if (grid[x][y] == '0') {
                    int dx[4] = {0, -1, 0, 1};
                    int dy[4] = {-1, 0, 1, 0};

                    int sub = 0;
                    for (int k = 0; k < 4; k++) {
                        auto newX = x + dx[k];
                        auto newY = y + dy[k];

                        while (0 <= newX && newX < row && 0 <= newY && newY < col && grid[newX][newY] != 'W') {
                            if (grid[newX][newY] == 'E') {
                                sub++;
                            }
                            newX += dx[k];
                            newY += dy[k];
                        }
                    }
                    res = max(res, sub);
                }
            }
        }

        return res;
    }
};
