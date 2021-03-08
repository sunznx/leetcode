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
                if (m.find(sub.first) != m.end() && m[sub.first] != pos) {
                    if (sub.second) {
                        ans.push_back({pos, m[sub.first]});
                    } else {
                        ans.push_back({m[sub.first], pos});
                    }
                }
            }
        }

        return ans;
    }

    vector<pair<string, bool>> calc(string &s) {
        vector<pair<string, bool>> ans;

        int len = s.size();
        vector<vector<bool>> dp(len+1, vector<bool>(len+1));

        for (int i = 0; i < len; i++) {
            dp[i][i] = true;
            if (i > 0 && s[i] == s[i-1]) {
                dp[i-1][i] = true;
            }
        }

        for (int i = len-1; i >= 0; i--) {
            for (int j = i+2; j < len; j++) {
                if (dp[i+1][j-1] && s[i] == s[j]) {
                    dp[i][j] = true;
                }
            }
        }

        for (int l = 0; l < len; l++) {
            string sub = s.substr(0, l);
            string rev = reverseStr(sub);
            if (m.find(rev) == m.end()) {
                continue;
            }

            if (dp[l][len-1]) {
                ans.push_back({rev, true});
            }
        }

        for (int l = 0; l < len; l++) {
            string sub = s.substr(len-l, l);
            string rev = reverseStr(sub);
            if (m.find(rev) == m.end()) {
                continue;
            }

            if (dp[0][len-1-l]) {
                ans.push_back({rev, false});
            }
        }

        string rev = reverseStr(s);
        if (rev != s) {
            ans.push_back({rev, true});
        }

        return ans;
    }

    string reverseStr(string &s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        return rev;
    }
};
