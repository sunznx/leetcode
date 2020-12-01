// CreateTime: 2020-12-01 20:45:44
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        int len1 = A.size();
        int len2 = B.size();

        int k1 = 0;
        int k2 = 0;

        vector<vector<int>> ans;

        while (k1 < len1 && k2 < len2) {
            int s1 = A[k1][0];
            int e1 = A[k1][1];

            int s2 = B[k2][0];
            int e2 = B[k2][1];

            // 不相交
            if (s2 > e1) {
                k1++;
                continue;
            }

            // 不相交
            if (s1 > e2) {
                k2++;
                continue;
            }

            // 相交
            ans.push_back({max(s1, s2), min(e1, e2)});
            if (e1 == e2) {
                k1++;
                k2++;
            } else if (e1 < e2) {
                k1++;
            } else if (e1 > e2) {
                k2++;
            }
        }

        return ans;
    }
};
