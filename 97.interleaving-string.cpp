// CreateTime: 2019-12-26 19:47:49
class Solution {
public:
    bool ok = false;

    unordered_map<int, unordered_map<int, unordered_map<int, bool>>> m;

    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) {
            return false;
        }
        return isInterleave(s1, s2, s3, 0, 0, 0);
    }

    bool isInterleave(string &s1, string &s2, string &s3, int k1, int k2, int k3) {
        if (m.find(k1) != m.end() && m[k1].find(k2) != m[k1].end() && m[k1][k2].find(k3) != m[k1][k2].end()) {
            return m[k1][k2][k3];
        }

        if (k3 == s3.size()) {
            return m[k1][k2][k3] = true;
        }

        if (s3[k3] == s1[k1] && s3[k3] == s2[k2]) {
            m[k1+1][k2][k3+1] = isInterleave(s1, s2, s3, k1+1, k2, k3+1);
            m[k1][k2+1][k3+1] = isInterleave(s1, s2, s3, k1, k2+1, k3+1);
            return m[k1][k2][k3] = m[k1+1][k2][k3+1] || m[k1][k2+1][k3+1];
        }

        if (s3[k3] == s1[k1]) {
            return m[k1][k2][k3] = isInterleave(s1, s2, s3, k1+1, k2, k3+1);
        }

        if (s3[k3] == s2[k2]) {
            return m[k1][k2][k3] = isInterleave(s1, s2, s3, k1, k2+1, k3+1);
        }

        return m[k1][k2][k3] = false;
    }
};
