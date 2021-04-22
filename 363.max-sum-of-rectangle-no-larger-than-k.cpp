// CreateTime: 2021-04-22 02:36:55
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int row = matrix.size();
        int col = matrix[0].size();

        int ans = INT_MIN;
        for (int i = 0; i < row; i++) {
            vector<int> sum(col);
            for (int m = i; m < row; m++) {
                for (int j = 0; j < col; j++) {
                    sum[j] += matrix[m][j];
                }

                set<int> S = {0};
                int s = 0;
                for (int j = 0; j < col; j++) {
                    s += sum[j];
                    auto iter = S.lower_bound(s-k);
                    if (iter != S.end()) {
                        ans = max(ans, s-*iter);
                    }
                    S.insert(s);
                }
            }
        }

        return ans;
    }
};