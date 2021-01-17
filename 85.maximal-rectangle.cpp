// CreateTime: 2021-01-17 15:59:37
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        auto row = matrix.size();
        if (row == 0) {
            return 0;
        }

        auto col = matrix[0].size();

        int ans = 0;
        vector<int> heights(col);

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (matrix[i][j] == '1') {
                    heights[j] += 1;
                } else {
                    heights[j] = 0;
                }
            }

            ans = max(ans, largestRectangleArea(heights));
        }

        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        int ans;
        stack<int> stk;

        int len = heights.size();

        vector<int> l(len);
        vector<int> r(len);

        stk = stack<int>();
        for (int i = 0; i < len; i++) {
            auto x = heights[i];

            while (stk.size() && x <= heights[stk.top()]) {
                stk.pop();
            }

            if (i != 0 && stk.size() == 0) {
                l[i] = i;
            } else if (i != -1 && stk.size()) {
                l[i] = i-stk.top()-1;
            }
            stk.push(i);
        }

        stk = stack<int>();
        for (int i = len-1; i >= 0; i--) {
            auto x = heights[i];

            while (stk.size() && x <= heights[stk.top()]) {
                stk.pop();
            }

            if (i != len-1 && stk.size() == 0) {
                r[i] = len-1-i;
            } else if (i != len-1 && stk.size()) {
                r[i] = stk.top()-i-1;
            }
            stk.push(i);
        }

        for (int i = 0; i < len; i++) {
            auto x = heights[i];
            ans = max(ans, (l[i]+r[i]+1)*x);
        }
        return ans;
    }
};
