// CreateTime: 2019-12-14 00:07:17
class Solution {
public:
    int heightChecker(vector<int>& heights) {
        auto h = heights;
        sort(h.begin(), h.end());
        
        int ans = 0;

        int len = heights.size();
        for (int i = 0; i < len; i++) {
            if (heights[i] != h[i]) {
                ans += 1;
            }
        }
        return ans;
    }
};
