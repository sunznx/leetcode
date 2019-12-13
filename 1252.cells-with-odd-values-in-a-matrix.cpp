// CreateTime: 2019-12-13 23:39:29
class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        vector<int> row(n);
        vector<int> col(m);
        
        int len = indices.size();
        for (int i = 0; i < len; i++) {
            auto x = indices[i][0];
            auto y = indices[i][1];
            row[x] += 1;
            col[y] += 1;
        }
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans += ((row[i] + col[j]) % 2 == 1);
            }
        }

        return ans;
    }
};
