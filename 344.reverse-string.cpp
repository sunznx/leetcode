class Solution {
public:
    string reverseString(string s) {
        if (s.size() <= 1) {
            return s;
        }

        for (int i = 0; i < s.size()/2; i++) {
            char c = s[i];
            s[i]= s[s.size()-1-i];
            s[s.size()-1-i] = c;
        }
        return s;
    }
};
