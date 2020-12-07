// CreateTime: 2020-12-07 07:52:58
class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        int row = A.size();
        if (row == 0) {
            return 0;
        }

        int col = A[0].size();

        for (int i = 0; i < row; i++) {
            if (A[i][0] == 0) {
                for (int j = 0; j < col; j++) {
                    A[i][j] = 1-A[i][j];
                }
            }
        }


        for (int j = 1; j < col; j++) {
            int zeros = 0;
            for (int i = 0; i < row; i++) {
                if (A[i][j] == 0) {
                    zeros++;
                }
            }

            // 0 的个数比 非0 的个数还多
            if (zeros > (row-zeros)) {
                for (int i = 0; i < row; i++) {
                    A[i][j] = 1-A[i][j];
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                ans += A[i][j] << (col-j-1);
            }
        }

        return ans;
    }
};
