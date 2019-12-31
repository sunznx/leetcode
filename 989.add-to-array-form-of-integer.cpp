// CreateTime: 2019-12-31 10:29:51
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        vector<int> v;
        while (K) {
            v.insert(v.begin(), K % 10);
            K = K / 10;
        }

        int cur = 0;
        int k = 0;
        while (cur || k < v.size() || k < A.size()) {
            auto n = cur;
            if (k < A.size()) {
                n += A[A.size()-k-1];
            }
            if (k < v.size()) {
                n += v[v.size()-k-1];
            }

            cur = n/10;

            if (k >= A.size()) {
                A.insert(A.begin(), n%10);
            } else {
                A[A.size()-k-1] = n%10;
            }

            k++;
        }
        return A;
    }
};