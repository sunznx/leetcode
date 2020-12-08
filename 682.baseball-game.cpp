// CreateTime: 2020-12-08 15:46:43
class Solution {
public:
    int calPoints(vector<string>& ops) {
        int ans = 0;
        
        stack<int> stk;
        for (int i = 0; i < ops.size(); i++) {
            if (ops[i] == "C") {
                auto top = stk.top();
                stk.pop();
                ans -= top;
            }
            else if (ops[i] == "D") {
                auto top = stk.top();
                stk.push(top * 2);
                ans += top * 2;
            }
            else if (ops[i] == "+") {
                auto top1 = stk.top();
                stk.pop();
                
                auto top2 = stk.top();
                stk.pop();
                
                stk.push(top2);
                stk.push(top1);
                stk.push(top1 + top2);
                ans += top1 + top2;
            }
            else {
                auto val = stoi(ops[i]);
                stk.push(val);
                ans += val;
            }
        }
        return ans;
    }
};
