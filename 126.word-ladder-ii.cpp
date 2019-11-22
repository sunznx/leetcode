// CreateTime: 2019-11-22 17:32:16
class Solution {
public:
    vector<vector<string>> res;
    unordered_set<string> s;
    unordered_map<string, int> m;
    unordered_map<string, unordered_set<string>> pre;
    vector<string> path;
    queue<string> q;

    void bfs(string &beginWord, string &endWord) {
        while (!q.empty()) {
            int len = q.size();
            for (int i = 0; i < len; i++) {
                auto str = q.front();
                q.pop();

                auto changableStrs = getChangableStrings(s, str);
                for (int i = 0; i < changableStrs.size(); i++) {
                    if (m.find(changableStrs[i]) == m.end() || m[changableStrs[i]] == m[str]+1) {
                        pre[changableStrs[i]].insert(str);
                        m[changableStrs[i]] = m[str] + 1;
                        if (changableStrs[i] == endWord) {
                            break;
                        } else {
                            q.push(changableStrs[i]);
                        }
                    }
                }
            }
        }

        generatePath(beginWord, endWord);
    }

    void generatePath(string &beginWord, string &endWord) {
        if (pre[endWord].size() == 0) {
            return;
        }

        res = {{endWord}};
        while (res[0][res[0].size()-1] != beginWord) {
            vector<vector<string>> newRes;
            for (int i = 0; i < res.size(); i++) {
                auto paths = splitPath(res[i][res[i].size()-1], res[i]);
                for (auto path: paths) {
                    newRes.push_back(path);
                }
            }
            res = newRes;
        }

        for (int i = 0; i < res.size(); i++) {
            reverse(res[i].begin(), res[i].end());
        }
    }

    vector<vector<string>> splitPath(string &p, vector<string>& v) {
        vector<vector<string>> res;

        for (auto n: pre[p]) {
            vector<string> newV = v;
            newV.push_back(n);
            res.push_back(newV);
        }

        return res;
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        for (int i = 0; i < wordList.size(); i++) {
            s.insert(wordList[i]);
        }

        q.push(beginWord);
        m[beginWord] = 1;
        bfs(beginWord, endWord);

        return res;
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
