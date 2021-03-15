// CreateTime: 2021-03-06 22:51:50
class Solution {
public:
    int beautySum(string s) {
        int ans = 0;

        int len = s.size();
        for (int i = 0; i < len; i++) {
            vector<int> m(256);
            for (int j = i; j < len; j++) {
                auto x = s[j];
                m[x]++;

                int minVal = INT_MAX;
                int maxVal = INT_MIN;
                for (int x = 'a'; x <= 'z'; x++) {
                    if (m[x] > 0) {
                        minVal = min(minVal, m[x]);
                        maxVal = max(maxVal, m[x]);
                    }
                }

                ans += maxVal-minVal;
            }
        }

        return ans;
    }
};