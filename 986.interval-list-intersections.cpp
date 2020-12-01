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

            if (s2 > e1) {
                k1++;
            } else if (s1 > e2) {
                k2++;
            } else if (s1 <= s2 && s2 <= e1) {
                if (e1 == e2) {
                    k1++;
                    k2++;
                    ans.push_back({s2, e1});
                } else if (e1 < e2) {
                    k1++;
                    ans.push_back({s2, e1});
                } else if (e1 > e2) {
                    k2++;
                    ans.push_back({s2, e2});
                }
            } else if (s2 <= s1 && s1 <= e2) {
                if (e1 == e2) {
                    k1++;
                    k2++;
                    ans.push_back({s1, e1});
                } else if (e1 < e2) {
                    k1++;
                    ans.push_back({s1, e1});
                } else if (e1 > e2) {
                    k2++;
                    ans.push_back({s1, e2});
                }
            }
        }

        return ans;
    }
};
