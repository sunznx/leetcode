// CreateTime: 2020-12-08 12:17:15
class Solution {
public:
    string removeDuplicates(string S) {
        stack<char> stk;

        for (int i = 0; i < S.size(); i++) {
            stk.push(S[i]);

            while (stk.size() >= 2) {
                auto top1 = stk.top();
                stk.pop();

                auto top2 = stk.top();
                stk.pop();

                if (top1 != top2) {
                    stk.push(top2);
                    stk.push(top1);
                    break;
                }
            }
        }

        string ans;
        while (stk.size()) {
            auto top = stk.top();
            stk.pop();
            ans.insert(ans.begin(), top);
        }
        return ans;
    }
};
