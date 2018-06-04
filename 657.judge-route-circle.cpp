class Solution {
public:
    bool judgeCircle(string moves) {
        int len = moves.size();
        if (len == 0) {
            return false;
        }

        int x = 0;
        int y = 0;
        for (int i = 0; i < len; i++) {
            if (moves[i] == 'U') {
                y += 1;
            } else if (moves[i] == 'D') {
                y -= 1;
            } else if (moves[i] == 'L') {
                x -= 1;
            } else if (moves[i] == 'R') {
                x += 1;
            }
        }

        if (x == 0 && y == 0) {
            return true;
        }

        return false;
    }
};
