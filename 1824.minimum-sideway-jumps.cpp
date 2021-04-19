// CreateTime: 2021-04-11 10:20:43
class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        int len = obstacles.size();

        vector<vector<int>> f(len+1, vector<int>(4, len+1));
        f[0][1] = 1;
        f[0][2] = 0;
        f[0][3] = 1;
        for (int i = 1; i < len; i++) {
            for (int k = 1; k <= 3; k++) {
                for (int j = 1; j <= 3; j++) {
                    if (k == obstacles[i] || j == obstacles[i] || j == obstacles[i-1]) {
                        continue;
                    }

                    if (j != k) {
                        f[i][k] = min(f[i][k], f[i-1][j]+1);
                    } else {
                        f[i][k] = min(f[i][k], f[i-1][j]);
                    }
                }
            }
        }

        return min({f[len-1][1], f[len-1][2], f[len-1][3]});
    }
};