class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int len = s.size();
        
        vector<int> res(len, len);
        for (int i = 0; i < len; i++) {
            if (s[i] == c) {
                for (int j = 0; j < len; j++) {
                    res[j] = min(res[j], abs(j-i));
                }
            }
        }
        
        return res;
    }
};
