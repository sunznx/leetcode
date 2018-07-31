class Solution {
public:
    vector<string> res;

    vector<string> generateParenthesis(int n) {
        if (n == 0) {
            return res;
        }

        string v = "";
        dfs(n, v, 0, 0);
        return res;
    }

    void dfs(int n, string &v, int l, int r) {
        if (l > n || r > n || r > l) {
            return;
        }

        if (2 * n == l+r) {
            res.push_back(v);
            return;
        }

        auto tmp = v;

        v = tmp;
        v = v + "(";
        dfs(n, v, l+1, r);

        v = tmp;
        v = v + ")";
        dfs(n, v, l, r+1);

        // if (l == n) {
        //     v = v + ")";
        //     dfs(n, v, l, r + 1);
        // } else if (r == n) {
        //     return;
        // } else if (l == r) {
        //     v = v + "(";
        //     dfs(n, v, l+1, r);
        // } else {
        //     auto tmp = v;

        //     v = tmp;
        //     v = v + "(";
        //     dfs(n, v, l+1, r);

        //     v = tmp;
        //     v = v + ")";
        //     dfs(n, v, l, r+1);
        // }
    }
};
