// CreateTime: 2021-04-29 01:05:11
class Solution {
public:
    vector<unordered_map<int, bool>> m;
    bool canCross(vector<int>& stones) {
        m.resize(stones.size());
        return dfs(stones);
    }

    bool dfs(vector<int> &stones, int step = 0, int k = 0) {
        if (step >= stones.size()-1) {
            return true;
        }

        if (m[step].find(k) != m[step].end()) {
            return m[step][k];
        }

        for (int i = step+1; i < stones.size(); i++) {
            auto x = stones[i] - stones[step];

            if (x > k+1) {
                break;
            }

            if (x == k-1 || x == k || x == k+1) {
                if (dfs(stones, i, x)) {
                    return m[step][k] = true;
                }
            }
        }

        return m[step][k] = false;
    }
};