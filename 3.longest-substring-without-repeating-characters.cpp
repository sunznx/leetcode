// CreateTime: 2021-01-12 16:48:00
class Solution {
public:
    int ans = 0;

    int lengthOfLongestSubstring(string s) {
        int l = 0;

        vector<int> m(256);

        for (int r = 0; r < s.size(); r++) {
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
