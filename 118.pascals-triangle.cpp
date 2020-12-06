// CreateTime: 2020-12-06 23:44:35
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        
        for (int i = 0; i < numRows; i++) {
            vector<int> v(i+1, 0);
            for (int j = 0; j <= i; j++) {
                if (i == 0 || i == j || j == 0) {
                    v[j] = 1;
                } else {
                    v[j] = res[i-1][j-1] + res[i-1][j];
                }
            }
            res.push_back(v);
        }

        return res;
    }
};
