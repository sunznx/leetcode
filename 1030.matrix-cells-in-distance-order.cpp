// CreateTime: 2019-12-31 17:09:00
class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<bool>> v(R, vector<bool>(C));
        vector<vector<int>> res;

        queue<pair<int, int>> q;
        q.push({r0, c0});
        v[r0][c0] = true;

        int dx[4] = {0, -1, 0, 1};
        int dy[4] = {-1, 0, 1, 0};

        while (!q.empty()) {
            auto top = q.front();
            q.pop();

            auto x = top.first;
            auto y = top.second;

            res.push_back({x, y});

            for (int k = 0; k < 4; k++) {
                auto newX = x + dx[k];
                auto newY = y + dy[k];

                if (newX < 0 || newX >= R || newY < 0 || newY >= C || v[newX][newY] == true) {
                    continue;
                }

                v[newX][newY] = true;
                q.push({newX, newY});
            }
        }

        return res;
    }
};
