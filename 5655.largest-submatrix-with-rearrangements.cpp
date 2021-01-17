// CreateTime: 2021-01-17 10:53:38
class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        auto row = matrix.size();
        if (row == 0) {
            return 0;
        }

        auto col = matrix[0].size();

        int ans = 0;
        vector<int> heights(col);

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (matrix[i][j]) {
                    heights[j] += 1;
                } else {
                    heights[j] = 0;
                }
            }

            auto sortedHeights = heights;
            sort(sortedHeights.begin(), sortedHeights.end(), greater<int>());
            for (int j = 0; j < col; j++) {
                ans = max(ans, sortedHeights[j] * (j+1));
            }
        }

        return ans;
    }
};