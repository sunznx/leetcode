// CreateTime: 2019-11-28 11:10:47
class Solution {
public:

    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        queue<pair<int, int>> q;

        int leaves = 0;
        int step = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
                if (grid[i][j] == 1) {
                    leaves += 1;
                }
            }
        }

        int dx[4] = {0, -1, 0, 1};
        int dy[4] = {-1, 0, 1, 0};

        while (leaves > 0 && ! q.empty()) {
            int len = q.size();
            step += 1;
            
            for (int i = 0; i < len; i++) {
                auto top = q.front();
                q.pop();
                
                auto x = top.first;
                auto y = top.second;
                
                for (int k = 0; k < 4; k++) {
                    auto newX = x + dx[k];
                    auto newY = y + dy[k];
                    
                    if (newX >= row || newX < 0 || newY >= col || newY < 0) {
                        continue;
                    }
                    
                    if (grid[newX][newY] == 1) {
                        grid[newX][newY] = 2;
                        q.push({newX, newY});
                        leaves -= 1;
                    }
                }
            }
        }
        
        if (leaves > 0) {
            return -1;
        }
        return step;
    }
};
