class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> s1;
        stack<char> s2;
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '#' && s1.size()) {
                s1.pop();
            } else if (s[i] != '#') {
                s1.push(s[i]);
            }
        }
        
        for (int i = 0; i < t.size(); i++) {
            if (t[i] == '#' && s2.size()) {
                s2.pop();
            } else if (t[i] != '#') {
                s2.push(t[i]);
            }
        }
        
        if (s1.size() != s2.size()) {
            return false;
        }
        
        int len = s1.size();
        while (len--) {
            char c1 = s1.top();
            char c2 = s2.top();
            
            if (c1 != c2) {
                return false;
            }
        }
        
        return true;
    }
};
