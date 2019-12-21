// CreateTime: 2019-12-21 09:34:15
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;

        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return res;
        }

        int row = matrix.size();
        int col = matrix[0].size();

        vector<int> s1 = {0, 0, col-1};
        vector<int> s2 = {col-1, 1, row-1};
        vector<int> s3 = {row-1, col-2, 0};
        vector<int> s4 = {0, row-2, 1};

        int tot = row * col;
        while (tot) {
            for (int i = s1[1]; i <= s1[2] && tot; i++) {
                res.push_back(matrix[s1[0]][i]);
                tot--;
            }
            s1[0]++;
            s1[1]++;
            s1[2]--;

            for (int i = s2[1]; i <= s2[2] && tot; i++) {
                res.push_back(matrix[i][s2[0]]);
                tot--;
            }
            s2[0]--;
            s2[1]++;
            s2[2]--;

            for (int i = s3[1]; i >= s3[2] && tot; i--) {
                res.push_back(matrix[s3[0]][i]);
                tot--;
            }
            s3[0]--;
            s3[1]--;
            s3[2]++;

            for (int i = s4[1]; i >= s4[2] && tot; i--) {
                res.push_back(matrix[i][s4[0]]);
                tot--;
            }
            s4[0]++;
            s4[1]--;
            s4[2]++;
        }
        return res;
    }
};
