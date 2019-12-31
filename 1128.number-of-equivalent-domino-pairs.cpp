// CreateTime: 2019-12-31 11:50:08
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int res = 0;

        unordered_map<int, unordered_map<int, int>> m;

        int len = dominoes.size();
        for (int i = 0; i < len; i++) {
            auto x = dominoes[i][0];
            auto y = dominoes[i][1];
            m[min(x, y)][max(x, y)]++;
        }

        for (auto &v: m) {
            for (auto &vv: v.second) {
                auto times = vv.second;
                res += times * (times-1) / 2; 
            }
        }

        return res;
    }
};
