// CreateTime: 2019-11-20 20:14:31
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int len = pushed.size();

        unordered_map<int, int> m;
        vector<bool> v(len);

        stack<int> s;

        for (int i = 0; i < len; i++) {
            m[pushed[i]] = i;
        }

        for (int i = 0; i < len; i++) {
            int curIdx = m[popped[i]];

            if (i != 0) {
                int preIdx = m[popped[i-1]];
                if (curIdx < preIdx) {
                    if (s.empty() || popped[i] != s.top()) {
                        return false;
                    } else {
                        s.pop();
                    }
                }
            }

            v[curIdx] = true;
            if (curIdx != 0 && !v[curIdx-1]) {
                s.push(pushed[curIdx-1]);
                v[curIdx-1] = true;
            }
        }

        return true;
    }
};
