// CreateTime: 2019-11-28 16:01:04
class Solution {
public:
    int countSegments(string s) {
        int len = s.size();
        int ans = 0;

        bool preIsSpace = true;
        for (int i = 0; i < len; i++) {
            if (s[i] == ' ') {
                preIsSpace = true;
            } else {
                if (preIsSpace) {
                    ans += 1;
                }
                preIsSpace = false;
            }
        }
        return ans;
    }
};
