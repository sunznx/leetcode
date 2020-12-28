// CreateTime: 2020-01-16 23:33:04
class Solution {
  public:
    int numTrees(int n) {
        vector<int> m(n+1);
        m[0] = 1;
        m[1] = 1;
        return f(m, n);
    }

    int f(vector<int> &m, int n) {
        if (m[n]) {
            return m[n];
        }

        int ans = 0;
        for (int i = 0; i <= n-1; i++) {
            ans += f(m, i) * f(m, n-1-i);
        }
        return m[n] = ans;
    }
};
