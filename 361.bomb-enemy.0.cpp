// CreateTime: 2020-01-19 16:12:59
class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) {
            return 0;
        }

        int row = grid.size();
        int col = grid[0].size();

        vector<vector<vector<int>>> c(row, vector<vector<int>>(col, vector<int>(4)));

        // 上下左右
        const int UP = 0;
        const int DOWN = 1;
        const int LEFT = 2;
        const int RIGHT = 3;

        // up
        for (int x = 1; x < row; x++) {
            for (int y = 0; y < col; y++) {
                if (grid[x-1][y] == 'E') {
                    c[x][y][UP] = c[x-1][y][UP] + 1;
                }
                if (grid[x-1][y] == '0') {
                    c[x][y][UP] = c[x-1][y][UP];
                }
            }
        }

        // down
        for (int x = row-2; x >= 0; x--) {
            for (int y = 0; y < col; y++) {
                if (grid[x+1][y] == 'E') {
                    c[x][y][DOWN] = c[x+1][y][DOWN] + 1;
                }
                if (grid[x+1][y] == '0') {
                    c[x][y][DOWN] = c[x+1][y][DOWN];
                }
            }
        }

        // left
        for (int x = 0; x < row; x++) {
            for (int y = 1; y < col; y++) {
                if (grid[x][y-1] == 'E') {
                    c[x][y][LEFT] = c[x][y-1][LEFT] + 1;
                }
                if (grid[x][y-1] == '0') {
                    c[x][y][LEFT] = c[x][y-1][LEFT];
                }
            }
        }

        // right
        for (int x = 0; x < row; x++) {
            for (int y = col-2; y >= 0; y--) {
                if (grid[x][y+1] == 'E') {
                    c[x][y][RIGHT] = c[x][y+1][RIGHT] + 1;
                }
                if (grid[x][y+1] == '0') {
                    c[x][y][RIGHT] = c[x][y+1][RIGHT];
                }
            }
        }

        int res = 0;
        for (int x = 0; x < row; x++) {
            for (int y = 0; y < col; y++) {
                if (grid[x][y] == '0') {
                    res = max(res, (c[x][y][0]+c[x][y][1]+c[x][y][2]+c[x][y][3]));
                }
            }
        }
        return res;
    }
};
