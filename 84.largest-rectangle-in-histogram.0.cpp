// CreateTime: 2021-01-17 15:20:24
class Solution {
public:
    int ans = 0;
    stack<int> stk;

    int largestRectangleArea(vector<int>& heights) {
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
