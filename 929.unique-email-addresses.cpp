// CreateTime: 2019-12-14 16:18:31
class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> s;

        for (auto &email: emails) {
            normalize(email);
            s.insert(email);
        }
        return s.size();
    }

    void normalize(string &s) {
        int k = 0;
        bool found = false;
        while (k < s.size()) {
            if (s[k] == '@') {
                break;
            }
            if (s[k] == '+') {
                found = true;
            }
            if (found) {
                s.erase(s.begin()+k);
            } else if (s[k] == '.') {
                s.erase(s.begin()+k);
            } else {
                k++;
            }
        }
    }
};
