// CreateTime: 2021-03-08 18:54:34
class Solution {
public:
    unordered_map<string, int> m;
    vector<vector<int>> ans;

    vector<vector<int>> palindromePairs(vector<string>& words) {
        for (int i = 0; i < words.size(); i++) {
            auto x = words[i];
            m[x] = i;
        }

        for (auto &x: m) {
            auto word = x.first;
            auto pos = x.second;
            calc(word, pos);
        }

        return ans;
    }

    void calc(string &s, int pos) {
        int len = s.size();
        for (int l = 0; l < len; l++) {
            string sub = s.substr(0, l);
            string rev = reverseStr(sub);

            if (m.find(rev) != m.end() && isPalindrome(s+rev)) {
                ans.push_back({pos, m[rev]});
            }
        }

        for (int l = 0; l < len; l++) {
            string sub = s.substr(len-l, l);
            string rev = reverseStr(sub);

            if (m.find(rev) != m.end() && isPalindrome(rev+s)) {
                ans.push_back({m[rev], pos});
            }
        }

        string rev = reverseStr(s);
        if (m.find(rev) != m.end() && rev != s) {
            ans.push_back({pos, m[rev]});
        }
    }

    string reverseStr(string &s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        return rev;
    }

    bool isPalindrome(string s) {
        int l = 0;
        int r = s.size()-1;

        while (l < r) {
            if (s[l] == s[r]) {
                l++;
                r--;
            } else {
                return false;
            }
        }
        return true;
    }
};
