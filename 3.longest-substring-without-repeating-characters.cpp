// CreateTime: 2019-12-05 15:36:20
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> m(256);

        int res = 0;
        int len = s.size();

        int last = -1;
        for (int i = 0; i < len; i++) {
            last = max(last, m[s[i]]-1);
            m[s[i]] = i+1;
            res = max(res, i-last);
        }

        return res;
    }
};
