// CreateTime: 2021-02-24 10:33:36
class Solution {
public:
    typedef pair<int, int> PII;

    int dx[4] = {0, -1, 0, 1};
    int dy[4] = {-1, 0, 1, 0};

    int minimumEffortPath(vector<vector<int>>& heights) {
        int row = heights.size();
        int col = heights[0].size();

        int l = 0;
        int r = 0;

        int minV = heights[0][0];
        int maxV = heights[0][0];
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                auto x = heights[i][j];
                minV = min(minV, x);
                maxV = max(maxV, x);
                r = max(r, abs(minV-maxV));
            }
        }

        while (l < r) {
            int m = (l+r) / 2;
            if (check(heights, m)) {
                r = m;
            } else {
                l = m+1;
            }
        }

        return l;
    }

    bool check(vector<vector<int>>& heights, int m) {
        int row = heights.size();
        int col = heights[0].size();

        vector<vector<bool>> seen(row, vector<bool>(col));

        queue<PII> que;
        que.push({0, 0});
        seen[0][0] = true;

        while (que.size()) {
            auto front = que.front();
            que.pop();

            auto x = front.first;
            auto y = front.second;
            auto val = heights[x][y];

            for (int k = 0; k < 4; k++) {
                auto newX = x + dx[k];
                auto newY = y + dy[k];

                if (0 <= newX && newX < row && 0 <= newY && newY < col && !seen[newX][newY]) {
                    auto newVal = heights[newX][newY];
                    if (abs(newVal-val) > m) {
                        continue;
                    }

                    if (newX == row-1 && newY == col-1) {
                        return true;
                    }

                    que.push({newX, newY});
                    seen[newX][newY] = true;
                }
            }
        }
        return false;
    }
};
