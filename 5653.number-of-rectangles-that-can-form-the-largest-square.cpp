// CreateTime: 2021-01-17 10:31:18
class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        unordered_map<int, int> m;
        int maxLen = 0;

        for (auto &x: rectangles) {
            auto k = min(x[0], x[1]);
            m[k]++;
            maxLen = max(maxLen, k);
        }

        return m[maxLen];
    }
};