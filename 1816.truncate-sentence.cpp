// CreateTime: 2021-04-04 10:30:05
class Solution {
public:
    string truncateSentence(string s, int k) {
        string ans;
        int m = 0;
        for (int i = 0; i < s.size(); i++) {
            ans += s[i];
            if (s[i] == ' ' || i == s.size()-1) {
                m++;
            }
            if (m == k) {
                break;
            }
        }
        if (ans.back() == ' ') {
            ans.pop_back();
        }
        return ans;
    }
};