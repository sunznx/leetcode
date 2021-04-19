// CreateTime: 2021-04-18 10:25:13
class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int len1 = arr1.size();
        int len2 = arr2.size();

        int x = 0;
        int y = 0;

        vector<int> m1(32);
        vector<int> m2(32);
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
            if (m1[k] % 2 == 1 && m2[k] % 2 == 1) {
                ans += (1<<k);
            }
        }
        return ans;
    }
};