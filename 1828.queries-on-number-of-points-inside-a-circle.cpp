// CreateTime: 2021-04-17 22:33:00
class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> ans(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            auto x = queries[i][0];
            auto y = queries[i][1];
            auto r = queries[i][2];

            for (auto &point: points) {
                auto p1 = point[0];
                auto p2 = point[1];

                if (r * r >= (p1-x)*(p1-x)+(p2-y)*(p2-y)) {
                    ans[i]++;
                }
            }
        }

        return ans;
    }
};