// CreateTime: 2019-11-23 08:42:06
class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_map<int, unordered_map<int, bool>> m;
        for (int i = 0; i < obstacles.size(); i++) {
            auto o1 = obstacles[i][0];
            auto o2 = obstacles[i][1];
            m[o1][o2] = true;
        }


        int dx[4] = {-1, 0, 1,  0};
        int dy[4] = { 0, 1, 0, -1};

        int k = 1;

        int x = 0;
        int y = 0;
        
        int res = 0;

        for (int i = 0; i < commands.size(); i++) {
            auto op = commands[i];
            if (op == -1) {
                k = (k+1) % 4;
            } else if (op == -2) {
                k = (k+4-1) % 4;                
            } else {
                for (int i = 1; i <= op; i++) {
                    x += dx[k];
                    if (m[x][y] == true) {
                        x -= dx[k];
                        break;
                    }
                }
                
                for (int i = 1; i <= op; i++) {
                    y += dy[k];
                    if (m[x][y] == true) {
                        y -= dy[k];
                        break;
                    }
                }
            }
            
            res = max(res, x*x + y*y);
        }
        
        return res;
    }
};
