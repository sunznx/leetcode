// CreateTime: 2021-03-18 00:21:20
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int row = matrix.size();
        int col = matrix[0].size();

        int l = matrix[0][0];
        int r = matrix[row-1][col-1];

        while (l < r) {
            int m = (l+r) / 2;
            if (check(matrix, k, m)) {
                r = m;
            } else {
                l = m+1;
            }
        }
        return l;
    }

    bool check(vector<vector<int>>& matrix, int k, int m) {
        int row = matrix.size();
        int col = matrix[0].size();
        int i = row-1;
        int j = 0;

        int cnt = 0;
        while (i >= 0 && j < col) {
            auto x = matrix[i][j];
            if (x <= m) {
                cnt += i+1;
                j++;
            } else {
                i--;
            }
        }
        return cnt >= k;
    }
};
