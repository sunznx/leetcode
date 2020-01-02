// CreateTime: 2020-01-02 17:22:02
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;

        int len = asteroids.size();
        for (int i = 0; i < len; i++) {
            if (res.size() == 0) {
                res.push_back(asteroids[i]);
                continue;
            }

            if (asteroids[i] < 0) {
                while (res.size() && res.back() >= 0 && -asteroids[i] > res.back()) {
                    res.pop_back();
                }

                if (res.size() && -asteroids[i] == res.back()) {
                    res.pop_back();
                    continue;
                }

                if (res.size() == 0 || res.back() < 0) {
                    res.push_back(asteroids[i]);
                }
            } else if (asteroids[i] >= 0) {
                res.push_back(asteroids[i]);
            }
        }

        return res;
    }
};
