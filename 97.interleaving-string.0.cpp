// CreateTime: 2019-12-26 20:17:13
class Solution {
public:
    vector<vector<int>> m;

    bool isInterleave(string s1, string s2, string s3) {
        auto l1 = s1.size();
        auto l2 = s2.size();
        auto l3 = s3.size();

        if (l1 + l2 != l3) {
            return false;
        }
        m.resize(l1+1, vector<int>(l3+1, -1));
        return isInterleave(s1, s2, s3, 0, 0, 0) > 0;
    }

    int isInterleave(string &s1, string &s2, string &s3, int k1, int k2, int k3) {
        if (m[k1][k3-k1] != -1) {
            return m[k1][k3-k1];
        }

        if (k3 == s3.size()) {
            return m[k1][k3-k1] = 1;
        }

        if (s3[k3] == s1[k1] && s3[k3] == s2[k2]) {
            m[k1+1][k3-k1] = isInterleave(s1, s2, s3, k1+1, k2, k3+1);
            m[k1][k3+1-k1] = isInterleave(s1, s2, s3, k1, k2+1, k3+1);
            return m[k1][k3-k1] = m[k1+1][k3-k1] || m[k1][k3+1-k1];
        }

        if (s3[k3] == s1[k1]) {
            return m[k1][k3-k1] = isInterleave(s1, s2, s3, k1+1, k2, k3+1);
        }

        if (s3[k3] == s2[k2]) {
            return m[k1][k3-k1] = isInterleave(s1, s2, s3, k1, k2+1, k3+1);
        }

        return m[k1][k3-k1] = 0;
    }
};
