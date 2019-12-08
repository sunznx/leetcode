// CreateTime: 2019-12-09 00:17:13
class Solution {
public:
    vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
        vector<int> res;
        unordered_map<int, int> m;

        int len;
        
        len = B.size();
        for (int i = 0; i < len; i++) {
            m[B[i]] = i;
        }

        len = A.size();
        for (int i = 0; i < len; i++) {
            res.push_back(m[A[i]]);
        }

        return res;
    }
};
