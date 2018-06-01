class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int raw = matrix.size();
        int col = matrix[0].size();

        vector<int> mark(raw+1, 0);
        int res;
        for (int n = 0; n < k; n++) {
            int min_idx;
            int cur_min;
            bool is_first = true;
            for (int i = 0; i < raw; i++) {
                if (mark[i] == col) {
                    continue;
                }

                if (is_first || matrix[i][mark[i]] < cur_min) {
                    is_first = false;
                    cur_min = matrix[i][mark[i]];
                    min_idx = i;
                    res = cur_min;
                }
            }

            mark[min_idx]++;
        }

        return res;
    }
};
