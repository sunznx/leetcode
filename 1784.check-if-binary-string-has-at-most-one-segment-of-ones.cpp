// CreateTime: 2021-03-07 10:30:22
class Solution {
public:
    bool checkOnesSegment(string s) {
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == '1' && s[i-1] == '0') {
                return false;
            }
        }
        return true;
    }
};