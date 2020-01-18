// CreateTime: 2020-01-18 10:36:59
class Solution {
public:
    vector<int> m;
    bool wordBreak(string s, vector<string>& wordDict) {
        sort(wordDict.begin(), wordDict.end(), [](const auto &a, const auto &b){
            return a.size() > b.size();
        });
        m.resize(s.size(), -1);
        return wordBreak(s, 0, wordDict) == 1;
    }

    int wordBreak(string s, int start, vector<string>& wordDict) {
        if (start == s.size()) {
            return 1;
        }

        if (m[start] != -1) {
            return m[start];
        }

        int len = wordDict.size();
        for (int i = 0; i < len; i++) {
            if (s.substr(start, wordDict[i].size()) == wordDict[i]) {
                if (wordBreak(s, start+wordDict[i].size(), wordDict)) {
                    return m[start] = 1;
                }
            }
        }
        return m[start] = 0;
    }
};
