class Solution {
public:
    vector<string> res;

    map<int, string> m;

    vector<string> letterCombinations(string digits) {
        int len = digits.size();
        if (len == 0) {
            return res;
        }

        m[1] = "";
        m[2] = "abc";
        m[3] = "def";
        m[4] = "ghi";
        m[5] = "jkl";
        m[6] = "mno";
        m[7] = "pqrs";
        m[8] = "tuv";
        m[9] = "wxyz";


        dfs(digits, "", len, 0, 0);
        return res;
    }

    void dfs(string &digits, string v, int n, int step, int index) {
        if (n == step) {
            res.push_back(v);
            return;
        }

        for (int i = index; i < n; i++) {
            int num = digits[i] - '0';

            for (int j = 0; j < m[num].size(); j++) {
                dfs(digits, v + m[num][j], n, step+1, i+1);
            }
        }
    }
};
