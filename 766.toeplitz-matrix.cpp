// CreateTime: 2019-12-31 11:19:38
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return true;
        }

        int row = matrix.size();
        int col = matrix[0].size();

        for (int x = 0; x < row-1; x++) {
            for (int y = 0; y < col; y++) {
                auto newX = x+1;
                auto newY = y+1;
                if (newX >= row || newY >= col) {
                    continue;
                }

                if (matrix[newX][newY] != matrix[x][y]) {
                    return false;
                }
            }
        }

        return true;
    }
};
