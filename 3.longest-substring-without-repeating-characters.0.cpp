// CreateTime: 2021-04-01 11:20:48
class Solution {
public:
    int ans = 0;

    int lengthOfLongestSubstring(string s) {
        vector<int> m(256);
        int l = 0;
        int len = s.size();
        for (int r = 0; r < len; r++) {
            auto x = s[r];
            m[x]++;

            while (m[x] > 1) {
                auto y = s[l++];
                m[y]--;
            }

            ans = max(ans, r-l+1);
        }

        return ans;
    }
};
