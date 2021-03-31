// CreateTime: 2021-03-28 10:30:25
class Solution {
public:
    int numDifferentIntegers(string word) {
        unordered_set<string> S;

        int len = word.size();
        int k = 0;

        string sub = "";
        while (k < len || sub.size()) {
            if (k >= len || 'a' <= word[k] && word[k] <= 'z') {
                if (sub.size()) {
                    format(sub);
                    S.insert(sub);
                    sub = "";
                }
            } else if ('0' <= word[k] && word[k] <= '9') {
                sub = sub + word[k];
            }
            k++;
        }
        return S.size();
    }

    void format(string &s) {
        while (s.size() > 1 && s[0] == '0') {
            s.erase(s.begin());
        }
    }
};