// CreateTime: 2019-11-27 11:34:03
class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        int len = A.size();
        vector<vector<int>> m(len, vector<int>(26, 0));

        vector<string> res;

        for (int i = 0; i < len; i++) {
            for (int j = 0; j < A[i].size(); j++) {
                int idx = A[i][j] - 'a';
                m[i][idx] += 1;
            }
        }

        for (int j = 0; j < 26; j++) {
            int cnt = len;
            for (int i = 0; i < len; i++) {
                cnt = min(cnt, m[i][j]);
            }

            while (cnt--) {
                res.push_back(string(1, j+'a'));
            }
        }

        return res;
    }
};

