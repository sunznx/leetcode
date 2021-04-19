// CreateTime: 2021-04-18 10:25:13
class Solution {
public:
    typedef long long LL;
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        LL len1 = arr1.size();
        LL len2 = arr2.size();

        LL x = 0;
        LL y = 0;

        vector<LL> m1(32);
        vector<LL> m2(32);
        for (int i = 0; i < len1; i++) {
            for (int k = 0; k <= 31; k++) {
                if ((arr1[i] & (1<<k))) {
                    m1[k]++;
                }
            }
        }
        for (int i = 0; i < len2; i++) {
            for (int k = 0; k <= 31; k++) {
                if ((arr2[i] & (1<<k))) {
                    m2[k]++;
                }
            }
        }

        int ans = 0;
        for (int k = 0; k <= 31; k++) {
            if (m1[k] > 0 && m2[k] > 0) {
                if (m1[k]*m2[k] % 2 == 1) {
                    ans += (1<<k);
                }
            }
        }
        return ans;
    }
};