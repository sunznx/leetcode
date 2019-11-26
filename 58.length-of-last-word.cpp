// CreateTime: 2019-11-26 15:54:43
class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = s.size();
        int ans = 0;
        bool started = false;
        for (int i = len-1; i >= 0; i--) {
            if (s[i] == ' ' && started == false) {
                continue;
            } else if (s[i] == ' ') {
                break;
            } else {
                started = true;
                ans += 1;
            }
        }
        return ans;
    }
};

