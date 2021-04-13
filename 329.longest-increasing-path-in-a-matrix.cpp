// CreateTime: 2021-04-13 16:29:37
class Solution {
public:
    vector<int> dx = {0, -1, 0, 1};
    vector<int> dy = {-1, 0, 1, 0};

    int ans = 0;

    vector<vector<int>> f;

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        auto row = matrix.size();
        auto col = matrix[0].size();

        f.resize(row, vector<int>(col));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                dfs(matrix, i, j);
            }
        }
        return ans;
    }

    int dfs(vector<vector<int>>& matrix, int x, int y) {
        auto row = matrix.size();
        auto col = matrix[0].size();

        if (0 > x || x >= row && 0 > y || y >= col) {
            return 0;
        }

        if (f[x][y]) {
            return f[x][y];
        }

        f[x][y] = 1;
        for (int k = 0; k < 4; k++) {
            auto newX = x + dx[k];
            auto newY = y + dy[k];

            if (0 <= newX && newX < row && 0 <= newY && newY < col) {
                if (matrix[newX][newY] > matrix[x][y]) {
                    f[x][y] = max(f[x][y], dfs(matrix, newX, newY)+1);
                }
            }
        }

        ans = max(ans, f[x][y]);
        return f[x][y];
    }
};
