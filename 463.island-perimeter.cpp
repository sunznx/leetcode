// [
//  [0,1,0,0],
//  [1,1,1,0],
//  [0,1,0,0],
//  [1,1,0,0]
// ]

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int res = 0;
        int raw = grid.size();
        int col = grid[0].size();

        vector<vector<bool>> v(raw, vector<bool>(col, false));

        for (int i = 0; i < raw; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1 && v[i][j] == false) {
                    return dfs(grid, v, i, j);
                }
            }
        }

        return res;
    }

    int getCurrentValue(vector<vector<int>>& grid, int x, int y) {
        return getUp(grid, x, y) + getDown(grid, x, y) + getLeft(grid, x, y) + getRight(grid, x, y);
    }

    int getUp(vector<vector<int>>& grid, int x, int y) {
        int raw = grid.size();
        int col = grid[0].size();
        if (grid[x][y] == 1 && (x == 0 || grid[x-1][y] == 0)) {
            return 1;
        }
        return 0;
    }

    int getDown(vector<vector<int>>& grid, int x, int y) {
        int raw = grid.size();
        int col = grid[0].size();
        if (grid[x][y] == 1 && (x == raw-1 || grid[x+1][y] == 0)) {
            return 1;
        }
        return 0;
    }

    int getLeft(vector<vector<int>>& grid, int x, int y) {
        int raw = grid.size();
        int col = grid[0].size();
        if (grid[x][y] == 1 && (y == 0 || grid[x][y-1] == 0)) {
            return 1;
        }
        return 0;
    }

    int getRight(vector<vector<int>>& grid, int x, int y) {
        int raw = grid.size();
        int col = grid[0].size();
        if (grid[x][y] == 1 && (y == col-1 || grid[x][y+1] == 0)) {
            return 1;
        }
        return 0;
    }

    int dfs(vector<vector<int>>& grid, vector<vector<bool>>& v, int x, int y) {
        int raw = grid.size();
        int col = grid[0].size();

        if (x < 0 || y < 0 || x >= raw || y >= col || v[x][y] == true || grid[x][y] == 0) {
            return 0;
        }

        v[x][y] = true;

        int current = getCurrentValue(grid, x, y);
        int res1 = dfs(grid, v, x, y+1);
        int res2 = dfs(grid, v, x, y-1);
        int res3 = dfs(grid, v, x+1, y);
        int res4 = dfs(grid, v, x-1, y);

        return res1 + res2 + res3 + res4 + current;
    }
};
