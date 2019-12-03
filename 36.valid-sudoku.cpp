class Solution {
public:
    int getIndex(int i, int j) {
        return j / 3 + (i / 3 * 3);
    }

    bool init(vector<vector<int>> &v1, vector<vector<int>> &v2, vector<vector<int>> &v3, vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    if (mark(v1, v2, v3, board, i, j, board[i][j] - '0') == false) {
                        return false;
                    }
                }
            }
        }

        return true;
    }

    bool check(vector<vector<int>> &v1, vector<vector<int>> &v2, vector<vector<int>> &v3, vector<vector<char>>& board, int i, int j, int num) {
        int idx = getIndex(i, j);
        if (v1[i][num] || v2[j][num] || v3[idx][num]) {
            return false;
        }

        return true;
    }

    bool mark(vector<vector<int>> &v1, vector<vector<int>> &v2, vector<vector<int>> &v3, vector<vector<char>>& board, int i, int j, int num) {
        int idx = getIndex(i, j);

        if (check(v1, v2, v3, board, i, j, num) == false) {
            return false;
        }

        board[i][j] = num + '0';
        v1[i][num] = 1;   // i 行已经有 num 了
        v2[j][num] = 1;   // j 列已经有 num 了
        v3[idx][num] = 1; // 第 idx 个 小方格已经有 num 了
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>> v1 (10, vector<int>(10, 0));
        vector<vector<int>> v2 (10, vector<int>(10, 0));
        vector<vector<int>> v3 (10, vector<int>(10, 0));

        return init(v1, v2, v3, board);
    }
};
