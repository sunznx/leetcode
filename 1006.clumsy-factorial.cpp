// CreateTime: 2021-04-01 21:04:09
class Solution {
public:
    int clumsy(int N) {
        stack<int> stk;
        stk.push(N);

        for (int i = 1; i <= N-1; i++) {
            auto x = N-i;
            if (i % 4 == 1) {
                auto top = stk.top();
                stk.pop();
                stk.push(top*x);
            } else if (i % 4 == 2) {
                auto top = stk.top();
                stk.pop();
                stk.push(top/x);
            } else if (i % 4 == 3) {
                stk.push(x);
            } else if (i % 4 == 0) {
                stk.push(-x);
            }
        }

        int ans = 0;
        while (stk.size()) {
            ans += stk.top();
            stk.pop();
        }
        return ans;
    }
};
