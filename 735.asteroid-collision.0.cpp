// CreateTime: 2020-12-07 11:14:56
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;

        for (int i = 0; i < asteroids.size(); i++) {
            auto x = asteroids[i];

            ans.push_back(x);

            while (ans.size() >= 2) {
                if (ans.back() > 0) {
                    break;
                }

                auto x = ans.back();
                ans.pop_back();

                auto b = ans.back();
                ans.pop_back();

                if (b < 0 && x < 0) {
                    ans.push_back(b);
                    ans.push_back(x);
                    break;
                }

                if (abs(x) == abs(b)) {
                    break;
                }

                if (abs(x) > abs(b)) {
                    ans.push_back(x);
                }

                if (abs(x) < abs(b)) {
                    ans.push_back(b);
                }
            }
        }

        return ans;
    }
};
