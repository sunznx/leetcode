// CreateTime: 2020-12-07 11:31:44
class Solution {
public:
    string normal(string &S) {
        string s;
        for (int i = 0; i < S.size(); i++) {
            auto x = S[i];
            
            if (x == '#' && s.size()) {
                s.pop_back();
            } else if (x != '#') {
                s.push_back(x);
            }
        }
        return s;
    }

    bool backspaceCompare(string S, string T) {
        string s = normal(S);        
        string t = normal(T);
        
        return s == t;
    }
};
