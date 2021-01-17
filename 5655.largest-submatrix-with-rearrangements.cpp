// CreateTime: 2021-01-17 10:53:38
class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        auto row = matrix.size();
        if (row == 0) {
            return 0;
        }

        auto col = matrix[0].size();

        vector<vector<int>> w(row, vector<int>(col));

        for (int i = 1; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (matrix[i][j]) {
                    matrix[i][j] += matrix[i-1][j];
                }
            }
        }

        int ans = 0;
        vector<int> counts(col);
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                counts[j] = matrix[i][j];
            }

            sort(counts.begin(), counts.end(), greater<int>());

            for (int j = 0; j < col; j++) {
                ans = max(ans, counts[j] * (j+1));
            }
        }

        return ans;
    }
};