// CreateTime: 2021-01-17 13:09:37
class Solution {
public:
    int maxSide = 0;
    int maximalSquare(vector<vector<char>>& matrix) {
        auto row = matrix.size();
        if (row == 0) {
            return 0;
        }

        auto col = matrix[0].size();

        vector<vector<int>> f(row, vector<int>(col));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (i == 0 || j == 0) {
                    f[i][j] = matrix[i][j]-'0';
                } else if (matrix[i][j] == '0') {
                    f[i][j] = 0;
                } else {
                    f[i][j] = min({f[i-1][j], f[i][j-1], f[i-1][j-1]}) + 1;
                }
                maxSide = max(maxSide, f[i][j]);
            }
        }

        return maxSide * maxSide;
    }
};
