// CreateTime: 2019-11-26 16:33:36
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int len = s.size();

        unordered_map<int, int> m1;
        unordered_map<int, int> m2;

        for (int i = 0; i < len; i++) {
            int idx1 = s[i] - 'a' + 1;
            int idx2 = t[i] - 'a' + 1;
            if (m1[idx1] == 0 && m2[idx2] == 0) {
                m1[idx1] = idx2;
                m2[idx2] = idx1;
            } else if (m1[idx1] == 0 && m2[idx2] != 0) {
                return false;
            } else if (m1[idx1] != 0 && m2[idx2] == 0) {
                return false;
            } else if (m1[idx1] != idx2 && m2[idx2] != idx1) {
                return false;
            }
        }

        return true;
    }
};
