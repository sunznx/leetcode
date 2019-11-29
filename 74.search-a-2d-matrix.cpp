// CreateTime: 2019-11-29 11:47:29
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        if (row == 0) {
            return false;
        }
        
        int col = matrix[0].size();
        if (col == 0) {
            return false;
        }

        int size = row * col;
        
        int l = 0;
        int r = size-1;
        while (l < r) {
            int mid = (l+r) / 2;
            int i = mid / col;
            int j = mid % col;

            if (matrix[i][j] < target) {
                l = mid+1;
            } else {
                r = mid;
            }
        }
        
        int x = l / col;
        int y = l % col;
        return matrix[x][y] == target;
    }
};
