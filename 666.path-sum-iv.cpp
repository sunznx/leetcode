// CreateTime: 2021-01-05 03:02:07
class Solution {
public:
    int ans = 0;

    typedef unordered_map<int, int> MII;

    int pathSum(vector<int>& nums) {
        unordered_map<int, MII> m(7);

        for (int i = 0; i < nums.size(); i++) {
            auto parsed = parseNum(nums[i]);
            auto x1 = parsed[0];
            auto x2 = parsed[1];
            auto x3 = parsed[2];
            m[x1][x2] = x3;
        }

        helper(m);

        return ans;
    }

    vector<int> parseNum(int x) {
        auto x3 = x % 10;
        x = x / 10;

        auto x2 = x % 10;
        x = x / 10;

        auto x1 = x;
        return {x1, x2, x3};
    }

    int left(int x) {
        return x * 2 - 1;
    }

    int right(int x) {
        return x * 2;
    }

    void helper(unordered_map<int, MII> &m, int depth = 1, int pos = 1, int cur = 0) {
        if (m.find(depth) == m.end() || m[depth].find(pos) == m[depth].end()) {
            return;
        }

        cur += m[depth][pos];

        auto l = left(pos);
        auto r = right(pos);

        if (m.find(depth+1) == m.end() || (m[depth+1].find(l) == m[depth+1].end() && m[depth+1].find(r) == m[depth+1].end())) {
            ans += cur;
            return;
        }

        helper(m, depth+1, l, cur);
        helper(m, depth+1, r, cur);
    }
};
