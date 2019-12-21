// CreateTime: 2019-12-21 09:51:20
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res;

        if (n == 0) {
            return res;
        }

        res.resize(n, vector<int>(n));

        vector<int> s1 = {0, 0, n-1};
        vector<int> s2 = {n-1, 1, n-1};
        vector<int> s3 = {n-1, n-2, 0};
        vector<int> s4 = {0, n-2, 1};

        int tot = n * n;
        int cnt = 1;
        while (tot) {
            for (int i = s1[1]; i <= s1[2] && tot; i++) {
                res[s1[0]][i] = cnt++;
                tot--;
            }
            s1[0]++;
            s1[1]++;
            s1[2]--;

            for (int i = s2[1]; i <= s2[2] && tot; i++) {
                res[i][s2[0]] = cnt++;
                tot--;
            }
            s2[0]--;
            s2[1]++;
            s2[2]--;

            for (int i = s3[1]; i >= s3[2] && tot; i--) {
                res[s3[0]][i] = cnt++;
                tot--;
            }
            s3[0]--;
            s3[1]--;
            s3[2]++;

            for (int i = s4[1]; i >= s4[2] && tot; i--) {
                res[i][s4[0]] = cnt++;
                tot--;
            }
            s4[0]++;
            s4[1]--;
            s4[2]++;
        }

        return res;
    }
};
