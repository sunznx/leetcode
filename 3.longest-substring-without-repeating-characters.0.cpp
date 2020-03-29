// CreateTime: 2020-03-29 16:05:01
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> m(256, -1);
        int ans = 0;
        int cur = 0;

        for (int i = 0; i < s.size(); i++) {
            int idx = s[i];
            int pos = m[idx];

            if (pos == -1) {             // 如果当前的这个字符串没出现过，cur++
                ans = max(ans, ++cur);
            } else if (i-cur > pos) {    // 如果之前出现过，且不在最长的里面
                ans = max(ans, ++cur);
            } else {                     // 如果之前出现过，且在最长的里面
                ans = max(ans, cur);
                cur = i - pos;
            }

            m[idx] = i;
        }

        return ans;
    }
};