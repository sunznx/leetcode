// CreateTime: 2019-11-29 11:52:58
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

        int maxl = 0;
        int maxr = col-1;
        for (int i = 0; i < row; i++) {
            int l = maxl;
            int r = maxr;

            if (matrix[i][l] > target) {
                return false;
            }

            while (l < r) {
                int mid = (l+r) / 2;
                if (matrix[i][mid] < target) {
                    l = mid+1;
                } else {
                    r = mid;
                    maxr = min(maxr, mid);
                }
            }

            if (matrix[i][l] == target) {
                return true;
            }
        }

        return false;
    }
};