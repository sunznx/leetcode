// CreateTime: 2021-03-08 18:54:34
class Solution {
public:
    unordered_map<string, int> m;

    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> ans;

        for (int i = 0; i < words.size(); i++) {
            auto x = words[i];
            m[x] = i;
        }

        for (auto &x: m) {
            auto word = x.first;
            auto pos = x.second;

            auto arr = calc(word);
            for (auto &sub: arr) {
                if (sub.second) {
                    ans.push_back({pos, sub.first});
                } else {
                    ans.push_back({sub.first, pos});
                }
            }
        }

        return ans;
    }

    vector<pair<int, bool>> calc(string &s) {
        vector<pair<int, bool>> ans;

        int len = s.size();
        // vector<vector<bool>> dp(len+1, vector<bool>(len+1));

        // for (int i = 0; i < len; i++) {
        //     dp[i][i] = true;
        //     if (i > 0 && s[i] == s[i-1]) {
        //         dp[i-1][i] = true;
        //     }
        // }

        // for (int i = len-1; i >= 0; i--) {
        //     for (int j = i+2; j < len; j++) {
        //         if (dp[i+1][j-1] && s[i] == s[j]) {
        //             dp[i][j] = true;
        //         }
        //     }
        // }

        // for (int l = 0; l < len; l++) {
        //     string sub = s.substr(0, l);
        //     string rev = reverseStr(sub);

        //     if (m.find(rev) != m.end() && dp[l][len-1]) {
        //         ans.push_back({m[rev], true});
        //     }
        // }

        // for (int l = 0; l < len; l++) {
        //     string sub = s.substr(len-l, l);
        //     string rev = reverseStr(sub);

        //     if (m.find(rev) != m.end() && dp[0][len-1-l]) {
        //         ans.push_back({m[rev], false});
        //     }
        // }

        for (int l = 0; l < len; l++) {
            string sub = s.substr(0, l);
            string rev = reverseStr(sub);

            if (m.find(rev) != m.end() && isPalindrome(s+rev)) {
                ans.push_back({m[rev], true});
            }
        }

        for (int l = 0; l < len; l++) {
            string sub = s.substr(len-l, l);
            string rev = reverseStr(sub);

            if (m.find(rev) != m.end() && isPalindrome(rev+s)) {
                ans.push_back({m[rev], false});
            }
        }

        string rev = reverseStr(s);
        if (m.find(rev) != m.end() && rev != s) {
            ans.push_back({m[rev], true});
        }

        return ans;
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
