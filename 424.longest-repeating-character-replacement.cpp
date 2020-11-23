// CreateTime: 2020-11-22 03:04:03
class Solution
{
public:
    int characterReplacement(string s, int k) {
        int len = s.size();
        if (len == 0) {
            return 0;
        }

        int left = 0;
        int right = 0;

        vector<int> m(256);
        int maxCharCount = 0;

        int ans = 0;

        while (right < len) {
            char c = s[right++];
            m[c]++;

            maxCharCount = max(maxCharCount, m[c]);

            if (right-left - maxCharCount > k) {
                char d = s[left++];
                m[d]--;
            }

            ans = max(ans, right-left);
        }

        return ans;
    }
};