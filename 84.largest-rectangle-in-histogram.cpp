// CreateTime: 2021-03-31 15:49:47
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans = 0;
        int len = heights.size();
        stack<int> stk;
        vector<int> l(len);
        vector<int> r(len);

        stk = stack<int>();
        for (int i = 0; i < len; i++) {
            auto x = heights[i];

            while (stk.size() && x <= heights[stk.top()]) {
                stk.pop();
            }

            if (stk.size() == 0) {
                l[i] = i;
            } else {
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

            if (stk.size() == 0) {
                r[i] = len-1-i;
            } else {
                r[i] = stk.top()-i-1;
            }

            stk.push(i);
        }

        for (int i = 0; i < len; i++) {
            ans = max(ans, heights[i] * (l[i] + 1 + r[i]));
        }
        return ans;
    }
};
