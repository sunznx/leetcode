// CreateTime: 2021-04-12 15:14:29
class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int len = s.size();

        vector<vector<int>> f(len+1, vector<int>(256));
        for (int i = 0; i < s.size(); i++) {
            auto x = s[i];
            f[i+1] = f[i];
            f[i+1][x]++;
        }

        vector<bool> ans;
        for (auto &query: queries) {
            auto i = query[0];
            auto j = query[1];
            auto k = query[2];

            int K = 0;
            for (char c = 'a'; c <= 'z'; c++) {
                if ((f[j+1][c]-f[i][c]) % 2 == 1) {
                    K++;
                }
            }

            ans.push_back(K/2 <= k);
        }

        return ans;
    }
};
