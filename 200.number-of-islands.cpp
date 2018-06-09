class Solution {
public:
    vector<int> v;
    int row;
    int col;

    vector<vector<char>> G;

    void dfs(int x, int y) {
        if (v[x*col+y] == 1) {
            return;
        }
        if (x < 0 || y < 0 || x >= row || y >= col) {
            return;
        }

        v[x*col+y] = 1;

        if (x > 0 && G[x-1][y] == '1') {
            dfs(x-1, y);
        }

        if (y > 0 && G[x][y-1] == '1') {
            dfs(x, y-1);
        }

        if (x+1 != row && G[x+1][y] == '1') {
            dfs(x+1, y);
        }

        if (y+1 != col && G[x][y+1] == '1') {
            dfs(x, y+1);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        row = grid.size();

        if (row == 0) {
            return 0;
        }

        col = grid[0].size();

        G = grid;

        int len = col * row;

        for (int i = 0; i <= len; i++) {
            v.push_back(0);
        }

        int count = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                int index = i*col + j;
                if (v[index] == 0 && grid[i][j] == '1') {
                    dfs(i, j);
                    count++;
                }
            }
        }

        return count;
    }
};
