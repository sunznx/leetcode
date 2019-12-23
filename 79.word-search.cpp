// CreateTime: 2019-12-23 16:05:11
class Solution {
public:
    vector<int> dx = {0, -1, 0, 1};
    vector<int> dy = {-1, 0, 1, 0};
    
    int row;
    int col;

    bool ok = false;
    vector<vector<bool>> v;

    bool exist(vector<vector<char>>& board, string word) {
        if (board.size() == 0 || board[0].size() == 0) {
            return word.size() == 0;
        }
        
        row = board.size();
        col = board[0].size();        
        v.resize(row, vector<bool>(col));

        for (int i = 0; i < row && !ok; i++) {
            for (int j = 0; j < col && !ok; j++) {
                dfs(board, word, i, j);
            }
        }
        
        return ok;
    }
    
    void dfs(vector<vector<char>>& board, string &word, int x, int y, int step = 0) {
        if (ok) {
            return;
        }

        if (word.size() == step) {
            ok = true;
            return;
        }

        if (x < 0 || x >= row || y < 0 || y >= col || v[x][y] || board[x][y] != word[step]) {
            return;
        }
        
        v[x][y] = true;
        
        for (int k = 0; k < 4; k++) {
            auto newX = x + dx[k];
            auto newY = y + dy[k];
            dfs(board, word, newX, newY, step+1);
        }

        v[x][y] = false;
    }
};
