// CreateTime: 2021-04-03 10:18:36
class Solution {
public:
    typedef tuple<int, int, int> TIII;

    vector<int> dx = { 0, -1, 0,  1};
    vector<int> dy = {-1,  0, 1,  0};

    int trapRainWater(vector<vector<int>>& heightMap) {
        if (heightMap.size() == 0 || heightMap[0].size() == 0) {
            return 0;
        }

        auto row = heightMap.size();
        auto col = heightMap[0].size();
        vector<vector<bool>> seen(row, vector<bool>(col));

        priority_queue<TIII, vector<TIII>, greater<TIII>> pq;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (i == 0 || j == 0 || i == row-1 || j == col-1) {
                    seen[i][j] = true;
                    pq.push({heightMap[i][j], i, j});
                }
            }
        }

        int ans = 0;
        while (pq.size()) {
            auto [h, x, y] = pq.top();
            pq.pop();

            for (int k = 0; k < 4; k++) {
                auto newX = x + dx[k];
                auto newY = y + dy[k];

                if (newX >= row || newY >= col || newX < 0 || newY < 0 || seen[newX][newY]) {
                    continue;
                }

                if (h > heightMap[newX][newY]) {
                    ans += h-heightMap[newX][newY];
                }

                seen[newX][newY] = true;
                pq.push({max(h, heightMap[newX][newY]), newX, newY});
            }
        }

        return ans;
    }
};
