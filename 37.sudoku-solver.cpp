class Solution {
public:
    int cnt = 0;

    void init(vector<vector<int>> &v1, vector<vector<int>> &v2, vector<vector<int>> &v3, vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    mark(v1, v2, v3, board, i, j, board[i][j] - '0');
                }
            }
        }
    }

    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<int>> v1 (10, vector<int>(10, 0));
        vector<vector<int>> v2 (10, vector<int>(10, 0));
        vector<vector<int>> v3 (10, vector<int>(10, 0));

        init(v1, v2, v3, board);

        dfs(v1, v2, v3, board, 0, 0);
    }

    bool check(vector<vector<int>> &v1, vector<vector<int>> &v2, vector<vector<int>> &v3, vector<vector<char>>& board, int i, int j, int num) {
        int idx = getIndex(i, j);
        if (v1[i][num] || v2[j][num] || v3[idx][num]) {
            return false;
        }

        return true;
    }

    void mark(vector<vector<int>> &v1, vector<vector<int>> &v2, vector<vector<int>> &v3, vector<vector<char>>& board, int i, int j, int num) {
        cnt += 1;
        int idx = getIndex(i, j);

        board[i][j] = num + '0';
        v1[i][num] = 1;   // i 行已经有 num 了
        v2[j][num] = 1;   // j 列已经有 num 了
        v3[idx][num] = 1; // 第 idx 个 小方格已经有 num 了
    }

    void unmark(vector<vector<int>> &v1, vector<vector<int>> &v2, vector<vector<int>> &v3, vector<vector<char>>& board, int i, int j) {
        cnt -= 1;
        int num = board[i][j] - '0';
        int idx = getIndex(i, j);

        board[i][j] = '.';
        v1[i][num] = 0;
        v2[j][num] = 0;
        v3[idx][num] = 0;
    }


    int getIndex(int i, int j) {
        return j / 3 + (i / 3 * 3);
    }

    bool dfs(vector<vector<int>> &v1, vector<vector<int>> &v2, vector<vector<int>> &v3, vector<vector<char>>& board, int x, int y) {
        if (cnt == 81) {
            return true;
        }

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (int k = 1; k <= 9; k++) {
                        if (check(v1, v2, v3, board, i, j, k)) {
                            mark(v1, v2, v3, board, i, j, k);
                            if (dfs(v1, v2, v3, board, i, j)) {
                                return true;
                            }
                            unmark(v1, v2, v3, board, i, j);
                        }
                    }
                    return false;
                }
            }
        }

        // 不应该会走到这里
        return true;
    }
};
