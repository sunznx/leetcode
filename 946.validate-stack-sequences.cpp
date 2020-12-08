// CreateTime: 2020-12-08 07:54:54
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stk;
        int k = 0;
        for (int i = 0; i < pushed.size(); i++) {
            auto x = pushed[i];
            stk.push(x);

            while (stk.size() && stk.top() == popped[k]) {
                k++;
                stk.pop();
            }
        }

        return k == popped.size();
    }
};
