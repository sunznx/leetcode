// CreateTime: 2019-12-16 12:34:24
class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        unordered_map<int, int> m;
        
        int len = A.size();
        for (int i = 0; i < len; i++) {
            m[A[i]] += 1;
            if (m[A[i]] == len/2) {
                return A[i];
            }
        }
        
        return -1;
    }
};
