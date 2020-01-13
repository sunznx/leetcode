// CreateTime: 2020-01-09 11:59:15
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return 0;
        }

        int row = matrix.size();
        int col = matrix[0].size();

        int dx[4] = {0, -1, 0, 1};
        int dy[4] = {-1, 0, 1, 0};

        queue<pair<int, int>> q;

        for (int x = 0; x < row; x++) {
            for (int y = 0; y < col; y++) {
                bool ok = true;
                for (int k = 0; k < 4; k++) {
                    auto newX = x + dx[k];
                    auto newY = y + dy[k];
                    if (newX < 0 || newX >= row || newY < 0 || newY >= col) {
                        continue;
                    }

                    if (matrix[newX][newY] < matrix[x][y]) {
                        ok = false;
                        break;
                    }
                }

                if (ok) {
                    q.push({x, y});
                }
            }
        }

        int res = 0;
        while (q.size()) {
            vector<vector<bool>> v(row, vector<bool>(col));

            res++;
            int len = q.size();
            for (int i = 0; i < len; i++) {
                auto top = q.front();
                q.pop();

                auto x = top.first;
                auto y = top.second;

                for (int k = 0; k < 4; k++) {
                    auto newX = x + dx[k];
                    auto newY = y + dy[k];
                    if (newX < 0 || newX >= row || newY < 0 || newY >= col || v[newX][newY] || matrix[newX][newY] <= matrix[x][y]) {
                        continue;
                    }

                    v[newX][newY] = true;
                    q.push({newX, newY});
                }
            }
        }

        return res;
    }
};
