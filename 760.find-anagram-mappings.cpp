// CreateTime: 2019-12-09 00:17:13
class Solution {
public:
    vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
        unordered_map<int, int> m;

        int len = B.size();
        for (int i = 0; i < len; i++) {
            m[B[i]] = i;
        }

        vector<int> res;
        for (auto &item: A) {
            res.push_back(m[item]);
        }

        return res;
    }
};
