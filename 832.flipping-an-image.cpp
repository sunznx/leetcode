class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int raw = A.size();
        if (raw == 0) {
            return A;
        }

        int col = A[0].size();

        for (int i = 0; i < raw; i++) {
            for (int j = 0; j < col; j++) {
                A[i][j] = (A[i][j] ^ 1);
            }
        }

        for (int i = 0; i < raw; i++) {
            for (int j = 0; j < col/2; j++) {
                int t = A[i][j];
                A[i][j] = A[i][col-1-j];
                A[i][col-1-j] = t;
            }
        }

        return A;
    }
};
