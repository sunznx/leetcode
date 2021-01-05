// CreateTime: 2021-01-06 00:06:47
class Solution {
public:
    int ans = INT_MAX;

    int minFallingPathSum(vector<vector<int>>& A) {
        auto row = A.size();
        auto col = A[0].size();

        vector<vector<int>> m(row, vector<int>(col, INT_MAX));

        for (int y = 0; y < col; y++) {
            helper(A, m, 0, y);
        }

        for (int y = 0; y < col; y++) {
            ans = min(ans, m[row-1][y]);
        }

        return ans;
    }

    inline void helper(vector<vector<int>>& A, vector<vector<int>> &m, int x, int y = 0, int cur = 0) {
        if (x >= A.size() || y < 0 || y >= A[0].size() || A[x][y]+cur >= m[x][y]) {
            return;
        }

        cur += A[x][y];
        m[x][y] = min(m[x][y], cur);
        helper(A, m, x+1, y-1, cur);
        helper(A, m, x+1, y, cur);
        helper(A, m, x+1, y+1, cur);
    }
};