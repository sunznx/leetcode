// CreateTime: 2021-04-13 01:32:13
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        auto row = matrix.size();
        auto col = matrix[0].size();
        
        bool row0 = false;
        bool col0 = false;
        
        for (int i = 0; i < row; i++) {
            if (matrix[i][0] == 0) {
                col0 = true;
                break;
            }
        }
        
        for (int j = 0; j < col; j++) {
            if (matrix[0][j] == 0) {
                row0 = true;
                break;
            }
        }
        
        for (int i = 1; i < row; i++) {
            for (int j = 1; j < col; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        for (int i = 1; i < row; i++) {
            for (int j = 1; j < col; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        
        if (row0 == true) {
            for (int j = 0; j < col; j++) {
                matrix[0][j] = 0;
            }
        }
        
        if (col0 == true) {
            for (int i = 0; i < row; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};
