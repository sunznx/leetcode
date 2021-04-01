// CreateTime: 2021-03-31 15:34:55
class Solution {
public:
    vector<int> bits;

    int maximalRectangle(vector<vector<char>>& matrix) {
        int row = matrix.size();
        if (row == 0) {
            return 0;
        }

        int col = matrix[0].size();

        bits.resize(col, 0);

        int ans = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (matrix[i][j] == '1') {
                    bits[j] += 1;
                } else {
                    bits[j] = 0;
                }
            }

            ans = max(ans, calc());
        }
        return ans;
    }

    int calc() {
        int len = bits.size();
        stack<int> stk;

        vector<int> l(len);
        vector<int> r(len);

        stk = stack<int>();
        for (int i = 0; i < len; i++) {
            auto x = bits[i];
            while (stk.size() && x <= bits[stk.top()]) {
                stk.pop();
            }

            if (stk.size() == 0) {
                l[i] = i;
            } else {
                l[i] = i-(stk.top()+1);
            }

            stk.push(i);
        }

        stk = stack<int>();
        for (int i = len-1; i >= 0; i--) {
            auto x = bits[i];
            while (stk.size() && x <= bits[stk.top()]) {
                stk.pop();
            }

            if (stk.size() == 0) {
                r[i] = len-1-i;
            } else {
                r[i] = stk.top()-(i+1);
            }

            stk.push(i);
        }

        int ans = 0;
        for (int i = 0; i < len; i++) {
            ans = max(ans, bits[i] * (l[i] + r[i] + 1));
        }
        return ans;
    }
};
