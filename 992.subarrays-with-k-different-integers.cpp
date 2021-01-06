// CreateTime: 2020-12-01 07:45:55
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        return numberOfNotMoreThan(A, K) - numberOfNotMoreThan(A, K-1);
    }

    int numberOfNotMoreThan(vector<int> &A, int K) {
        int ans = 0;

        int l = 0;
        unordered_map<int, int> m;

        for (int i = 0; i < A.size(); i++) {
            auto x = A[i];
            m[x]++;

            while (m.size() > K) {
                auto y = A[l++];
                m[y]--;
                if (m[y] == 0) {
                    m.erase(y);
                }
            }

            ans += i-l+1;
        }

        return ans;
    }
};
