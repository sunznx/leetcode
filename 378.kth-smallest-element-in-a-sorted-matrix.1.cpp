// CreateTime: 2021-03-18 00:58:21
class Solution {
public:
    typedef pair<int, int> PII;
    typedef pair<int, PII> PIII;

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int row = matrix.size();
        int col = matrix[0].size();

        priority_queue<PIII, vector<PIII>, greater<PIII>> pq;

        vector<vector<bool>> seen(row, vector<bool>(col));
        pq.push({matrix[0][0], {0, 0}});
        seen[0][0] = true;

        while (--k) {
            auto top = pq.top();
            pq.pop();

            auto x = top.second.first;
            auto y = top.second.second;

            if (0 <= x+1 && x+1 < row && !seen[x+1][y]) {
                pq.push({matrix[x+1][y], {x+1, y}});
                seen[x+1][y] = true;
            }
            if (0 <= y+1 && y+1 < col && !seen[x][y+1]) {
                pq.push({matrix[x][y+1], {x, y+1}});
                seen[x][y+1] = true;
            }
        }

        return pq.top().first;
    }
};
