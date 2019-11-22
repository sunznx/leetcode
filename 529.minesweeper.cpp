// CreateTime: 2019-11-22 21:46:58
class Solution {
public:
    int step = 8;
    int dx[8] = {-1, -1, -1, 0,  0,  1, 1, 1};
    int dy[8] = {-1,  0,  1, -1, 1, -1, 0, 1};

    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        vector<vector<char>> newBoard = board;
        auto x = click[0];
        auto y = click[1];

        if (newBoard[x][y] == 'M') {
            newBoard[x][y] = 'X';
        } else {
            dfs(newBoard, x, y);
        }

        return newBoard;
    }

    void dfs(vector<vector<char>> &board, int x, int y) {
        update(board, x, y);
        if (board[x][y] == 'B') {
            int row = board.size();
            int col = board[0].size();

            for (int i = 0; i < step; i++) {
                auto newX = x+dx[i];
                auto newY = y+dy[i];

                if (newX < 0 || newX >= row || newY < 0 || newY >= col) {
                    continue;
                }

                if (board[newX][newY] == 'E') {
                    dfs(board, newX, newY);
                }
            }
        }
    }

    void update(vector<vector<char>> &board, int x, int y) {
        int row = board.size();
        int col = board[0].size();

        int cnt = 0;
        for (int i = 0; i < step; i++) {
            auto newX = x+dx[i];
            auto newY = y+dy[i];

            if (newX < 0 || newX >= row || newY < 0 || newY >= col) {
                continue;
            }

            if (board[newX][newY] == 'M') {
                cnt += 1;
            }
        }

        if (cnt == 0) {
            board[x][y] = 'B';
        } else {
            board[x][y] = '0' + cnt;
        }
    }
};
