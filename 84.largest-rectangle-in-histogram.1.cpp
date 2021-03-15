// CreateTime: 2021-03-15 19:43:50
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int len = heights.size();
        vector<int> l(len);
        vector<int> r(len);
        stack<int> stk;

        stk = stack<int>();
        for (int i = 0; i < len; i++) {
            auto x = heights[i];
            while (stk.size() && heights[stk.top()] >= x) {
                stk.pop();
            }

            if (stk.size() == 0) {
                l[i] = i;
            } else {
                l[i] = i-stk.top()-1;
            }
            stk.push(i);

            printf("l[%d] = %d\n", i, l[i]);
        }

        stk = stack<int>();
        for (int i = len-1; i >= 0; i--) {
            auto x = heights[i];
            while (stk.size() && heights[stk.top()] >= x) {
                stk.pop();
            }

            if (stk.size() == 0) {
                r[i] = len-1-i;
            } else {
                r[i] = stk.top()-i-1;
            }
            stk.push(i);

            printf("r[%d] = %d\n", i, r[i]);
        }

        int ans = 0;
        for (int i = 0; i < len; i++) {
            auto x = heights[i];
            ans = max(ans, (l[i] + r[i] + 1) * x);
        }
        return ans;
    }
};
