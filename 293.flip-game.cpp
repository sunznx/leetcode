// CreateTime: 2019-12-24 05:04:25
class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> res;

        int len = s.size();
        for (int i = 1; i < len; i++) {
            if (s[i] == '+' && s[i-1] == '+') {
                s[i] = '-';
                s[i-1] = '-';
                res.push_back(s);
                s[i] = '+';
                s[i-1] = '+';
            }
        }
        
        return res;
    }
};
