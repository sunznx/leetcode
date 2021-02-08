// CreateTime: 2021-02-08 18:34:25
class Solution {
public:
    static bool cmp(vector<int> &x, vector<int> &y) {
        return x[1] < y[1];
    }

    int maxValue(vector<vector<int>>& events, int k) {
        int len = events.size();

        sort(events.begin(), events.end(), cmp);

        vector<vector<int>> f(len+1, vector<int>(k+1));

        for (int i = 1; i <= len; i++) {
            auto start = events[i-1][0];
            auto end   = events[i-1][1];
            auto val   = events[i-1][2];

            int last = 0;
            for (int z = i-1; z >= 1; z--) {
                if (events[z-1][1] < start) {
                    last = z;
                    break;
                }
            }

            for (int j = 1; j <= k; j++) {
                f[i][j] = max({f[i-1][j], f[last][j-1]+val});
            }
        }

        return f[len][k];
    }
};
