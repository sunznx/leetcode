// CreateTime: 2020-11-20 17:26:55
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.size();

        int left = 0;
        int right = 0;
        int res = 0;

        unordered_map<char, int> window;

        while (right < len) {
            char c = s[right++];
            window[c]++;

            while (window[c] > 1) {
                char d = s[left++];
                window[d]--;
            }

            res = max(res, right-left);
        }

        return res;
    }
};