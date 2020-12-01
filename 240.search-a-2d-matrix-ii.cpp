// CreateTime: 2020-12-01 23:45:57
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

        int x = row-1;
        int y = 0;

        while (y <= col-1 && x >= 0) {
            auto num = matrix[x][y];

            if (target > num) {
                y++;
            } else if (target < num) {
                x--;
            } else if (num == target) {
                return true;
            }
        }

        return false;
    }
};