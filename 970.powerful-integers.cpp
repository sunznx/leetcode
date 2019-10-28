// CreateTime: 2019-10-28 17:27:11
class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        // if (x > y) {
        //     return powerfulIntegers(y, x, bound);
        // }

        if (x == 1 && y == 1) {
            vector<int> res;
            if (bound >= 2) {
                res.push_back(2);
            }
            return res;
        }

        if (x == 1) {
            return powerfulIntegers(x, y, 0, 1e6, bound);
        }
        return powerfulIntegers(x, y, 1e6, 1e6, bound);
    }

    vector<int> powerfulIntegers(int x, int y, int X, int Y, int bound) {
        vector<int> res;
        set<int> s;

        for (int i = 0; i <= X; i++) {
            int p1 = pow(x, i);
            if (p1 > bound) {
                break;
            }

            for (int j = 0; j <= Y; j++) {
                int p2 = pow(y, j);
                if (p1 + p2 > bound) {
                    break;
                }
                s.insert(p1+p2);
            }
        }

        for (auto iter = s.begin(); iter != s.end(); iter++) {
            res.push_back(*iter);
        }
        return res;
    }
};
