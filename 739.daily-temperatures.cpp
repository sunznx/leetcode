// CreateTime: 2020-01-02 17:14:09
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int len = T.size();
        vector<int> res(len);

        stack<int> s;

        for (int i = len-1; i >= 0; i--) {
            while (s.size() && T[i] >= T[s.top()]) {
                s.pop();
            }

            if (s.size()) {
                res[i] = s.top()-i;
            } else {
                res[i] = 0;
            }

            s.push(i);
        }

        return res;
    }
};
