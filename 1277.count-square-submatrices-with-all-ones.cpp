// CreateTime: 2021-01-17 13:28:15
class Solution {
public:
    int ans;

    int countSquares(vector<vector<int>>& matrix) {
        auto row = matrix.size();
        auto col = matrix[0].size();

        vector<vector<int>> f(row, vector<int>(col));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (i == 0 || j == 0) {
                    f[i][j] = matrix[i][j];
                } else if (matrix[i][j] == 0) {
                    f[i][j] = 0;
                } else {
                    f[i][j] = min({f[i][j-1], f[i-1][j], f[i-1][j-1]}) + 1;
                }
                ans += f[i][j];
            }
        }

        return ans;
    }
};
