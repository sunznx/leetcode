//  CreateTime: 2021-01-24 10:55:27
class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        auto row = matrix.size();
        auto col = matrix[0].size();
        vector<vector<int>> f(row+1, vector<int>(col+1));
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (i == 0 && j == 0) {
                    f[i][j] = matrix[i][j];
                } else if (i == 0) {
                    f[i][j] = f[i][j-1] ^ matrix[i][j];
                } else if (j == 0) {
                    f[i][j] = f[i-1][j] ^ matrix[i][j];
                } else {
                    f[i][j] = f[i-1][j]^f[i][j-1] ^ f[i-1][j-1] ^ matrix[i][j];
                }

                if (pq.size() < k) {
                    pq.push(f[i][j]);
                } else {
                    auto top = pq.top();
                    if (f[i][j] > top) {
                        pq.pop();
                        pq.push(f[i][j]);
                    }
                }
            }
        }

        return pq.top();
    }
};