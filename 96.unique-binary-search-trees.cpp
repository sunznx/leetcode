// CreateTime: 2020-01-16 23:33:04
class Solution {
  public:
    vector<int> m;

    int numTrees(int n) {
        m.resize(max(3, n+1));

        m[0] = 1;
        m[1] = 1;
        m[2] = 2;
        return f(n);
    }

    int f(int n) {
        if (m[n]) {
            return m[n];
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            res += f(i) * f(n-1-i);
        }
        return m[n] = res;
    }
};
