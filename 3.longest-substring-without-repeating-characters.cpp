// CreateTime: 2021-01-12 16:48:00
class Solution {
public:
    int ans = 0;

    int lengthOfLongestSubstring(string s) {
        int l = 0;

        vector<int> m(256);

        for (int i = 0; i < s.size(); i++) {
            auto x = s[i];
            m[x]++;

            while (m[x] > 1) {
                auto y = s[l++];
                m[y]--;
            }

            ans = max(ans, i-l+1);
        }

        return ans;
    }
};
