// CreateTime: 2019-11-30 15:51:07
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int len = A.size();

        unordered_map<int, int> m1;
        unordered_map<int, int> m2;

        for (int i = 0; i < len; i++) {
            int a1 = A[i];
            int c1 = C[i];

            for (int j = 0; j < len; j++) {
                int b2 = B[j];
                int d2 = D[j];

                m1[a1+b2] += 1;
                m2[c1+d2] += 1;
            }
        }

        int ans = 0;
        for (auto item: m1) {
            int first = item.first;
            int second = item.second;
            ans += second * m2[-first];
        }
        return ans;
    }
};

