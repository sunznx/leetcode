// CreateTime: 2021-03-14 10:35:30
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int, int> m;
        int maxn = 0;
        int ans = -1;

        for (auto &edge: edges) {
            auto x = edge[0];
            auto y = edge[1];
            m[x]++;
            m[y]++;

            if (m[x] > maxn) {
                maxn = m[x];
                ans = x;
            }
            if (m[y] > maxn) {
                maxn = m[y];
                ans = y;
            }
        }

        return ans;
    }
};