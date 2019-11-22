// CreateTime: 2019-11-22 08:50:25
class Solution {
public:
    void bfs(queue<string> &q, unordered_map<string, int> &m, unordered_set<string> &s, string &endWord) {
        while (!q.empty()) {
            auto str = q.front();
            q.pop();

            auto changableStrs = getChangableStrings(s, str);
            for (int i = 0; i < changableStrs.size(); i++) {
                if (m.find(changableStrs[i]) == m.end()) {
                    m[changableStrs[i]] = m[str] + 1;

                    q.push(changableStrs[i]);

                    if (changableStrs[i] == endWord) {
                        return;
                    }
                }
            }
        }
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s;
        unordered_map<string, int> m;
        queue<string> q;

        for (int i = 0; i < wordList.size(); i++) {
            s.insert(wordList[i]);
        }

        q.push(beginWord);
        m[beginWord] = 1;

        bfs(q, m, s, endWord);

        return m[endWord];
    }

    vector<string> getChangableStrings(unordered_set<string>& s, string &str) {
        vector<string> res;

        char c;
        for (int i = 0; i < str.size(); i++) {
            c = str[i];

            for (int k = 0; k <= 26; k++) {
                str[i] = 'a' + k;
                if (s.find(str) != s.end()) {
                    res.push_back(str);
                }
            }

            str[i] = c;
        }

        return res;
    }
};
