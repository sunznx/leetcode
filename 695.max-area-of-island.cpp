// [
//  [0,0,1,0,0,0,0,1,0,0,0,0,0],
//  [0,0,0,0,0,0,0,1,1,1,0,0,0],
//  [0,1,1,0,1,0,0,0,0,0,0,0,0],
//  [0,1,0,0,1,1,0,0,1,0,1,0,0],
//  [0,1,0,0,1,1,0,0,1,1,1,0,0],
//  [0,0,0,0,0,0,0,0,0,0,1,0,0],
//  [0,0,0,0,0,0,0,1,1,1,0,0,0],
//  [0,0,0,0,0,0,0,1,1,0,0,0,0]
// ]

// [
//  [1,1,0,0,0],
//  [1,1,0,0,0],
//  [0,0,0,1,1],
//  [0,0,0,1,1]
// ]

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;
        int raw = grid.size();
        int col = grid[0].size();

        vector<vector<bool>> v(raw, vector<bool>(col, false));

        for (int i = 0; i < raw; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1 && v[i][j] == false) {
                    res = max(res, dfs(grid, v, i, j));
                }
            }
        }

        return res;
    }

    int dfs(vector<vector<int>>& grid, vector<vector<bool>>& v, int x, int y) {
        int raw = grid.size();
        int col = grid[0].size();

        if (x < 0 || y < 0 || x >= raw || y >= col || v[x][y] == true || grid[x][y] == 0) {
            return 0;
        }

        v[x][y] = true;

        int res1 = dfs(grid, v, x, y+1);
        int res2 = dfs(grid, v, x, y-1);
        int res3 = dfs(grid, v, x+1, y);
        int res4 = dfs(grid, v, x-1, y);

        return res1 + res2 + res3 + res4 + 1;
    }
};
