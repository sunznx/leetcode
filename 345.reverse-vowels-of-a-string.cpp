class Solution {
public:
    bool isYuan(char c) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            return true;
        }
        
        if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            return true;
        }
        
        return false;
    }

    string reverseVowels(string s) {
        int len = s.size();
        vector<int> t;
        for (int i = 0; i < len; i++) {
            if (isYuan(s[i])) {
                t.push_back(i);
            }
        }
        
        int tl = t.size();
        for (int i = 0; i < tl/2; i++) {
            int idx1 = t[i];
            int idx2 = t[tl-1-i];
            
            char c = s[idx1];
            s[idx1] = s[idx2];
            s[idx2] = c;
        }
        
        return s;
    }
};
