// CreateTime: 2020-11-24 20:12:19
class Solution {
public:
    string pushDominoes(string dominoes) {
        int len = dominoes.size();
        vector<int> l(len);
        vector<int> r(len);

        int f;

        f = 0;
        for (int i = 0; i < len; i++) {
            if (dominoes[i] == 'R') {
                f = len;
            }
            if (dominoes[i] == 'L') {
                f = 0;
            }
            if (dominoes[i] == '.') {
                f = max(f-1, 0);
            }
            l[i] = f;
        }

        f = 0;
        for (int i = len-1; i >= 0; i--) {
            if (dominoes[i] == 'L') {
                f = len;
            }
            if (dominoes[i] == 'R') {
                f = 0;
            }
            if (dominoes[i] == '.') {
                f = max(f-1, 0);
            }
            r[i] = f;
        }

        string ans;
        for (int i = 0; i < len; i++) {
            if (l[i] == r[i]) {
                ans.push_back('.');
            }
            if (l[i] > r[i]) {
                ans.push_back('R');
            }
            if (l[i] < r[i]) {
                ans.push_back('L');
            }
        }
        return ans;
    }
};
