// CreateTime: 2019-12-26 19:47:49
class Solution {
public:
    vector<vector<vector<int>>> m;
    int l1;
    int l2;
    int l3;

    bool isInterleave(string s1, string s2, string s3) {
        l1 = s1.size();
        l2 = s2.size();
        l3 = s3.size();

        if (l1 + l2 != l3) {
            return false;
        }

        m.resize(l1+1, vector<vector<int>>(l2+1, vector<int>(l3+1, -1)));
        isInterleave(s1, s2, s3, 0, 0, 0);
        return m[l1][l2][l3] > 0;
    }

    void isInterleave(string &s1, string &s2, string &s3, int k1, int k2, int k3) {
        if (m[k1][k2][k3] != -1) {
            return;
        }

        if (k3 == l3) {
            m[k1][k2][k3] = 1;
            return;
        }

        if (k1 < l1 && k2 < l2 && k3 < l3 && s3[k3] == s1[k1] && s3[k3] == s2[k2]) {
            isInterleave(s1, s2, s3, k1+1, k2, k3+1);
            isInterleave(s1, s2, s3, k1, k2+1, k3+1);
            m[k1][k2][k3] = m[k1+1][k2][k3+1] || m[k1][k2+1][k3+1];
            return;
        } else if (k1 < l1 && k3 < l3 && s3[k3] == s1[k1]) {
            isInterleave(s1, s2, s3, k1+1, k2, k3+1);
            return;
        }

        if (k2 < l2 && k3 < l3 && s3[k3] == s2[k2]) {
            isInterleave(s1, s2, s3, k1, k2+1, k3+1);
            return;
        }

        m[k1][k2][k3] = 0;
    }
};
